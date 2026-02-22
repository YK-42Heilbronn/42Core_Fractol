/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:12:57 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 16:06:12 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// mouse wheel up:: ydelta = 1
// mouse wheel down:: ydelta = -1
// static zoom: relative to window
void my_scrollhook(double xdelta, double ydelta, void* param)
{
	uint32_t width;
	uint32_t height;
	double offset;  // magnitude
	int forward;  // direction
	int backward;  // direction

	width = ((t_set_params*)param)->img->width;
	height = ((t_set_params*)param)->img->height;
	offset = 0.1;
	forward = 1;
	backward = -1;

	// // shift center focus
	// mandelbrot(((t_set_params*)param)->img, width, height, param);

	// expand | shrink picture w.r.t window or image
	if (ydelta > 0 && xdelta == 0) // scroll up i.e: Zoom in
	{
		((t_set_params*)param)->img_offset_x[0] = offset*forward;  // +ve
		((t_set_params*)param)->img_offset_x[1] = offset*backward; // -ve
		((t_set_params*)param)->img_offset_y[0] = offset*forward;  // +ve
		((t_set_params*)param)->img_offset_y[1] = offset*backward; // -ve
		// // cursor point zoom effect
		// ((t_set_params*)param)->img_offset_x[0] = -(offset+0.1)*((t_set_params*)param)->img_offset_x[0];
		// ((t_set_params*)param)->img_offset_x[1] = -(offset+0.1)*((t_set_params*)param)->img_offset_x[1];
		// ((t_set_params*)param)->img_offset_y[0] = -(offset+0.1)*((t_set_params*)param)->img_offset_y[0];
		// ((t_set_params*)param)->img_offset_y[1] = -(offset+0.1)*((t_set_params*)param)->img_offset_y[1];
	}
	if (ydelta < 0 && xdelta == 0) // scroll down i.e: Zoom out
	{
		((t_set_params*)param)->img_offset_x[0] = offset*backward; // -ve
		((t_set_params*)param)->img_offset_x[1] = offset*forward;  // +ve
		((t_set_params*)param)->img_offset_y[0] = offset*backward;  // -ve
		((t_set_params*)param)->img_offset_y[1] = offset*forward;  // +ve
		// // cursor point zoom effect
		// ((t_set_params*)param)->img_offset_x[0] = offset*((t_set_params*)param)->img_offset_x[0];
		// ((t_set_params*)param)->img_offset_x[1] = offset*((t_set_params*)param)->img_offset_x[1];
		// ((t_set_params*)param)->img_offset_y[0] = offset*((t_set_params*)param)->img_offset_y[0];
		// ((t_set_params*)param)->img_offset_y[1] = offset*((t_set_params*)param)->img_offset_y[1];
	}
	mandelbrot(param);

}


