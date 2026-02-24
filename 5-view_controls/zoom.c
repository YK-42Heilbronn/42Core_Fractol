/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:12:57 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 10:36:47 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// scale_y must also be updated, while zoom factor is not constant in all directions
void	zoom_view(double xdelta, double ydelta, void *frctl)
{
	t_set_params	*s_params;
	t_view_params	*v_params;

	s_params = &((t_fractol *)frctl)->s_params;
	v_params = &((t_fractol *)frctl)->v_params;
	v_params->scale_x = min_max_diff(&(s_params->image.a_x));
	v_params->scale_y = min_max_diff(&(s_params->image.a_y));
	if (ydelta > 0 && xdelta == 0)
	{
		s_params->image.offset_x.min = (v_params->offset * v_params->scale_x) * v_params->forward;
		s_params->image.offset_x.max = (v_params->offset * v_params->scale_x) * v_params->backward;
		s_params->image.offset_y.min = (v_params->offset * v_params->scale_y) * v_params->forward;
		s_params->image.offset_y.max = (v_params->offset * v_params->scale_y) * v_params->backward;
	}
	if (ydelta < 0 && xdelta == 0)
	{
		s_params->image.offset_x.min = (v_params->offset * v_params->scale_x) * v_params->backward;
		s_params->image.offset_x.max = (v_params->offset * v_params->scale_x) * v_params->forward;
		s_params->image.offset_y.min = (v_params->offset * v_params->scale_y) * v_params->backward;
		s_params->image.offset_y.max = (v_params->offset * v_params->scale_y) * v_params->forward;
	}
	display_set(frctl);
}
