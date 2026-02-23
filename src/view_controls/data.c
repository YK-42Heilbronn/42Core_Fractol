/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 14:49:59 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	update_image_axes_range(t_set_params *set_params)
{
	// coordinate - x
	set_params->image.a_x.min = set_params->image.a_x.min
		+ set_params->image.offset_x.min;
	// shrinking/expanding from min x coordinate(which is -ve)
	set_params->image.a_x.max = set_params->image.a_x.max
		+ set_params->image.offset_x.max;
	// shrinking/expanding from max x coordinate(which is +ve)
	// coordinate - y
	set_params->image.a_y.min = set_params->image.a_y.min
		+ set_params->image.offset_y.min;
	// shrinking/expanding from min y coordinate(which is -ve)
	set_params->image.a_y.max = set_params->image.a_y.max
		+ set_params->image.offset_y.max;
	// shrinking/expanding from max y coordinate(which is +ve)
	// printf("offset x: %f %f\n", set_params->image.offset_x.min,
	// set_params->image.offset_x.max);
	// printf("offset y: %f %f\n", set_params->image.offset_y.min,
	// set_params->image.offset_y.max);
}

// dynamic zoom: relative to pattern(picture)
void	cursor_data(double xpos, double ypos, void *frctl)
{
	((t_fractol *)frctl)->window.cursor.x = xpos;
	((t_fractol *)frctl)->window.cursor.y = ypos;
}

// // void my_scrollhook(double xdelta, double ydelta, void* param)
// // {
// // 	uint32_t width;
// // 	uint32_t height;
// // 	double offset;  // magnitude
// // 	int forward;  // direction
// // 	int backward;  // direction

// // 	width = ((t_set_params*)param)->img->width;
// // 	height = ((t_set_params*)param)->img->height;
// // 	offset = 1;
// // 	forward = 1;
// // 	backward = -1;

// // 	// // shift center focus
// // 	// mandelbrot(((t_set_params*)param)->img, width, height, param);
// // 	printf("scaling factor in x and y from min side:: %f - %f\n",
// // 		((t_set_params*)param)->img_offset_x[0],
// // 		((t_set_params*)param)->img_offset_y[0]);
// // 	// expand | shrink picture w.r.t window or image
// // 	if (ydelta > 0 && xdelta == 0) // scroll up i.e: Zoom in
// // 	{
//
// 		((t_set_params*)param)->img_offset_x[0] = (offset*forward)*((t_set_params*)param)->img_offset_x[0];
// // +ve
//
// 		((t_set_params*)param)->img_offset_x[1] = (offset*backward)*((t_set_params*)param)->img_offset_x[1];
// // -ve
//
// 		((t_set_params*)param)->img_offset_y[0] = (offset*forward)*((t_set_params*)param)->img_offset_y[0];
// // +ve
//
// 		((t_set_params*)param)->img_offset_y[1] = (offset*backward)*((t_set_params*)param)->img_offset_y[1];
// // -ve
// // 		// // cursor point zoom effect
// // 		// ((t_set_params*)param)->img_offset_x[0] =
// 			-(offset+0.1)*((t_set_params*)param)->img_offset_x[0];
// // 		// ((t_set_params*)param)->img_offset_x[1] =
// 			-(offset+0.1)*((t_set_params*)param)->img_offset_x[1];
// // 		// ((t_set_params*)param)->img_offset_y[0] =
// 			-(offset+0.1)*((t_set_params*)param)->img_offset_y[0];
// // 		// ((t_set_params*)param)->img_offset_y[1] =
// 			-(offset+0.1)*((t_set_params*)param)->img_offset_y[1];
// // 	}
// // 	if (ydelta < 0 && xdelta == 0) // scroll down i.e: Zoom out
// // 	{
//
// 		((t_set_params*)param)->img_offset_x[0] = (offset*backward)*((t_set_params*)param)->img_offset_x[0];
// // -ve
//
// 		((t_set_params*)param)->img_offset_x[1] = (offset*forward)*((t_set_params*)param)->img_offset_x[1];
// // +ve
//
// 		((t_set_params*)param)->img_offset_y[0] = (offset*backward)*((t_set_params*)param)->img_offset_y[0];
// // -ve
//
// 		((t_set_params*)param)->img_offset_y[1] = (offset*forward)*((t_set_params*)param)->img_offset_y[1];
// // +ve
// // 		// // cursor point zoom effect
//
// 		// ((t_set_params*)param)->img_offset_x[0] = offset*((t_set_params*)param)->img_offset_x[0];
//
// 		// ((t_set_params*)param)->img_offset_x[1] = offset*((t_set_params*)param)->img_offset_x[1];
//
// 		// ((t_set_params*)param)->img_offset_y[0] = offset*((t_set_params*)param)->img_offset_y[0];
//
// 		// ((t_set_params*)param)->img_offset_y[1] = offset*((t_set_params*)param)->img_offset_y[1];
// // 	}
// // 	printf("cursor pos in pixel plane:: %f :
// 		%f\n",((t_set_params*)param)->cursor_x,
// 		((t_set_params*)param)->cursor_y);
// // 	printf("cursor pos in pattern plane:: %f :
// 		%f\n*******************\n",transform_pixels_to_pattern_coordinates(((t_set_params*)param)->cursor_x,&((t_set_params*)param)->plane_params.x),
//
// 						transform_pixels_to_pattern_coordinates(((t_set_params*)param)->cursor_y,&((t_set_params*)param)->plane_params.y));
// // 	mandelbrot(((t_set_params*)param)->img, width, height, param);

// // }