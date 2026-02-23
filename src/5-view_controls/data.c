/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:23:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:41:26 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
// coordinate - x
shrinking/expanding from min x coordinate(which is -ve)
shrinking/expanding from max x coordinate(which is +ve)
// coordinate - y
shrinking/expanding from min y coordinate(which is -ve)
shrinking/expanding from max y coordinate(which is +ve)
*/
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

// dynamic zoom: relative to pattern(picture)
void	cursor_data(double xpos, double ypos, void *frctl)
{
	((t_fractol *)frctl)->window.cursor.x = xpos;
	((t_fractol *)frctl)->window.cursor.y = ypos;
}
