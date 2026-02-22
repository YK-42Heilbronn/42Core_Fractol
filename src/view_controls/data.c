/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 16:10:44 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	update_image_axes_range(t_set_params *set_params)
{
	// coordinate - x
	set_params->image.a_x.min = set_params->image.a_x.min
		+ set_params->image.offset.x;
		// shrinking/expanding from min x coordinate(which is -ve)
	set_params->image.a_x.max = set_params->image.a_x.max
		+ set_params->image.offset.x;
		// shrinking/expanding from max x coordinate(which is +ve)
	// coordinate - y
	set_params->image.a_y.min = set_params->image.a_y.min
		+ set_params->image.offset.y;
		// shrinking/expanding from min y coordinate(which is -ve)
	set_params->image.a_y.max = set_params->image.a_y.max
		+ set_params->image.offset.y;
		// shrinking/expanding from max y coordinate(which is +ve)
}

void	reset_offset_values(t_set_params *set_params)
{
	set_params->img_offset_x[0] = 0.0;
	set_params->img_offset_x[1] = 0.0;
	set_params->img_offset_y[0] = 0.0;
	set_params->img_offset_y[1] = 0.0;
}

// dynamic zoom: relative to pattern(picture)
void	my_cursorhook(double xpos, double ypos, void *param)
{
	double	pattern_x;
	double	pattern_y;

	// double center_x;
	// double center_y;
	// uint32_t w;
	// uint32_t h;
	pattern_x = transform_pixels_to_pattern_coordinates(xpos,
			&((t_set_params *)param)->plane_params.x);
	pattern_y = transform_pixels_to_pattern_coordinates(ypos,
			&((t_set_params *)param)->plane_params.y);
	((t_set_params *)param)->cursor_x = xpos;
	((t_set_params *)param)->cursor_y = ypos;
	// center_x = transform_pixels_to_pattern_coordinates(((t_set_params*)param)->img->width/2,
			&((t_set_params*)param)->plane_params.x);
	// center_y = transform_pixels_to_pattern_coordinates(((t_set_params*)param)->img->height/2,
			&((t_set_params*)param)->plane_params.y);
	printf("win:: xpos=%f - ypos=%f\n", xpos, ypos);
	printf("img:: xpos=%f - ypos=%f\n", pattern_x, pattern_y);
	// printf("window center in pattern: %f, %f\n", center_x, center_y);
	// printf("diff(old-new): %f, %f \n---------------\n", center_x-pattern_x,
		center_y-pattern_y);
	((t_set_params *)param)->img_offset_x[0] = normalize_value(pattern_x,
			(((t_set_params *)param)->plane_params.x.pattern_axis_limits), 0);
	((t_set_params *)param)->img_offset_x[1] = normalize_value(pattern_x,
			(((t_set_params *)param)->plane_params.x.pattern_axis_limits), 1);
	((t_set_params *)param)->img_offset_y[0] = normalize_value(pattern_y,
			(((t_set_params *)param)->plane_params.y.pattern_axis_limits), 0);
	((t_set_params *)param)->img_offset_y[1] = normalize_value(pattern_y,
			(((t_set_params *)param)->plane_params.y.pattern_axis_limits), 1);
	// printf("%f - %f\n-------\n", ((t_set_params*)param)->img_offset_x[0],
		((t_set_params*)param)->img_offset_x[1]);
	// printf("%f : %f\n", transform_pixels_to_pattern_coordinates(WIDTH/2,
			&((t_set_params*)param)->plane_params.x),
	// 					transform_pixels_to_pattern_coordinates(HEIGHT/2,
							&((t_set_params*)param)->plane_params.y));
	// w = ((t_set_params*)param)->img->width;
	// h = ((t_set_params*)param)->img->height;
	// mandelbrot(((t_set_params*)param)->img, w, h, ((t_set_params*)param));
}

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 	uint32_t width;
// 	uint32_t height;
// 	double offset;  // magnitude
// 	int forward;  // direction
// 	int backward;  // direction

// 	width = ((t_set_params*)param)->img->width;
// 	height = ((t_set_params*)param)->img->height;
// 	offset = 1;
// 	forward = 1;
// 	backward = -1;

// 	// // shift center focus
// 	// mandelbrot(((t_set_params*)param)->img, width, height, param);
// 	printf("scaling factor in x and y from min side:: %f - %f\n",
// 		((t_set_params*)param)->img_offset_x[0],
// 		((t_set_params*)param)->img_offset_y[0]);
// 	// expand | shrink picture w.r.t window or image
// 	if (ydelta > 0 && xdelta == 0) // scroll up i.e: Zoom in
// 	{
// 		((t_set_params*)param)->img_offset_x[0] = (offset*forward)*((t_set_params*)param)->img_offset_x[0]; 
			// +ve
// 		((t_set_params*)param)->img_offset_x[1] = (offset*backward)*((t_set_params*)param)->img_offset_x[1];
			// -ve
// 		((t_set_params*)param)->img_offset_y[0] = (offset*forward)*((t_set_params*)param)->img_offset_y[0]; 
			// +ve
// 		((t_set_params*)param)->img_offset_y[1] = (offset*backward)*((t_set_params*)param)->img_offset_y[1];
			// -ve
// 		// // cursor point zoom effect
// 		// ((t_set_params*)param)->img_offset_x[0] =
			-(offset+0.1)*((t_set_params*)param)->img_offset_x[0];
// 		// ((t_set_params*)param)->img_offset_x[1] =
			-(offset+0.1)*((t_set_params*)param)->img_offset_x[1];
// 		// ((t_set_params*)param)->img_offset_y[0] =
			-(offset+0.1)*((t_set_params*)param)->img_offset_y[0];
// 		// ((t_set_params*)param)->img_offset_y[1] =
			-(offset+0.1)*((t_set_params*)param)->img_offset_y[1];
// 	}
// 	if (ydelta < 0 && xdelta == 0) // scroll down i.e: Zoom out
// 	{
// 		((t_set_params*)param)->img_offset_x[0] = (offset*backward)*((t_set_params*)param)->img_offset_x[0];
			// -ve
// 		((t_set_params*)param)->img_offset_x[1] = (offset*forward)*((t_set_params*)param)->img_offset_x[1]; 
			// +ve
// 		((t_set_params*)param)->img_offset_y[0] = (offset*backward)*((t_set_params*)param)->img_offset_y[0]; 
			// -ve
// 		((t_set_params*)param)->img_offset_y[1] = (offset*forward)*((t_set_params*)param)->img_offset_y[1]; 
			// +ve
// 		// // cursor point zoom effect
// 		// ((t_set_params*)param)->img_offset_x[0] = offset*((t_set_params*)param)->img_offset_x[0];
// 		// ((t_set_params*)param)->img_offset_x[1] = offset*((t_set_params*)param)->img_offset_x[1];
// 		// ((t_set_params*)param)->img_offset_y[0] = offset*((t_set_params*)param)->img_offset_y[0];
// 		// ((t_set_params*)param)->img_offset_y[1] = offset*((t_set_params*)param)->img_offset_y[1];
// 	}
// 	printf("cursor pos in pixel plane:: %f : %f\n",
		((t_set_params*)param)->cursor_x, ((t_set_params*)param)->cursor_y);
// 	printf("cursor pos in pattern plane:: %f : %f\n*******************\n",
		transform_pixels_to_pattern_coordinates(((t_set_params*)param)->cursor_x,
			&((t_set_params*)param)->plane_params.x),
// 						transform_pixels_to_pattern_coordinates(((t_set_params*)param)->cursor_y,
							&((t_set_params*)param)->plane_params.y));
// 	mandelbrot(((t_set_params*)param)->img, width, height, param);

// }