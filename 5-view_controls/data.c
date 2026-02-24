/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 08:15:18 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	update_image_axes_range(t_set_params *set_params)
{
	set_params->image.a_x.min = set_params->image.a_x.min
		+ set_params->image.offset_x.min;
	set_params->image.a_x.max = set_params->image.a_x.max
		+ set_params->image.offset_x.max;
	set_params->image.a_y.min = set_params->image.a_y.min
		+ set_params->image.offset_y.min;
	set_params->image.a_y.max = set_params->image.a_y.max
		+ set_params->image.offset_y.max;
}

void	cursor_data(double xpos, double ypos, void *frctl)
{
	((t_fractol *)frctl)->window.cursor.x = xpos;
	((t_fractol *)frctl)->window.cursor.y = ypos;
}
