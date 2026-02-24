/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:12:57 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 08:15:29 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_view(double xdelta, double ydelta, void *frctl)
{
	t_set_params	*s_params;
	t_view_params	*v_params;

	s_params = &((t_fractol *)frctl)->s_params;
	v_params = &((t_fractol *)frctl)->v_params;
	if (ydelta > 0 && xdelta == 0)
	{
		s_params->image.offset_x.min = v_params->offset * v_params->forward;
		s_params->image.offset_x.max = v_params->offset * v_params->backward;
		s_params->image.offset_y.min = v_params->offset * v_params->forward;
		s_params->image.offset_y.max = v_params->offset * v_params->backward;
	}
	if (ydelta < 0 && xdelta == 0)
	{
		s_params->image.offset_x.min = v_params->offset * v_params->backward;
		s_params->image.offset_x.max = v_params->offset * v_params->forward;
		s_params->image.offset_y.min = v_params->offset * v_params->backward;
		s_params->image.offset_y.max = v_params->offset * v_params->forward;
	}
	display_set(frctl);
}
