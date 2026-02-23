/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:12:57 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 14:55:30 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// mouse wheel up:: ydelta = 1
// mouse wheel down:: ydelta = -1
// static zoom: relative to window
void	zoom_view(double xdelta, double ydelta, void *frctl)
{
	t_set_params	*s_params;
	t_view_params	*v_params;

	s_params = &((t_fractol *)frctl)->s_params;
	v_params = &((t_fractol *)frctl)->v_params;
	// // shift center focus
	// mandelbrot(((t_set_params*)param)->img, width, height, param);
	// expand | shrink picture w.r.t image
	if (ydelta > 0 && xdelta == 0) // scroll up i.e: Zoom in
	{
		s_params->image.offset_x.min = v_params->offset * v_params->forward;  //+ve
		s_params->image.offset_x.max = v_params->offset * v_params->backward; //-ve
		s_params->image.offset_y.min = v_params->offset * v_params->forward;  //+ve
		s_params->image.offset_y.max = v_params->offset * v_params->backward; //-ve
	}
	if (ydelta < 0 && xdelta == 0) // scroll down i.e: Zoom out
	{
		s_params->image.offset_x.min = v_params->offset * v_params->backward; //-ve
		s_params->image.offset_x.max = v_params->offset * v_params->forward;  //+ve
		s_params->image.offset_y.min = v_params->offset * v_params->backward; //-ve
		s_params->image.offset_y.max = v_params->offset * v_params->forward;  //+ve
	}
	display_set(frctl);
}
