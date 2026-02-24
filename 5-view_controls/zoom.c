/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:12:57 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 14:15:22 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// scale_y must also be updated, while zoom factor
// is not constant in all directions
void	zoom_view(double xdelta, double ydelta, void *frctl)
{
	t_set_params	*s_p;
	t_view_params	*v_p;

	s_p = &((t_fractol *)frctl)->s_p;
	v_p = &((t_fractol *)frctl)->v_p;
	v_p->scale_x = min_max_diff(&(s_p->image.a_x));
	v_p->scale_y = min_max_diff(&(s_p->image.a_y));
	if (ydelta > 0 && xdelta == 0)
	{
		s_p->image.offset_x.min = (v_p->offset * v_p->scale_x) * v_p->forward;
		s_p->image.offset_x.max = (v_p->offset * v_p->scale_x) * v_p->backward;
		s_p->image.offset_y.min = (v_p->offset * v_p->scale_y) * v_p->forward;
		s_p->image.offset_y.max = (v_p->offset * v_p->scale_y) * v_p->backward;
	}
	if (ydelta < 0 && xdelta == 0)
	{
		s_p->image.offset_x.min = (v_p->offset * v_p->scale_x) * v_p->backward;
		s_p->image.offset_x.max = (v_p->offset * v_p->scale_x) * v_p->forward;
		s_p->image.offset_y.min = (v_p->offset * v_p->scale_y) * v_p->backward;
		s_p->image.offset_y.max = (v_p->offset * v_p->scale_y) * v_p->forward;
	}
	display_set(frctl);
}
