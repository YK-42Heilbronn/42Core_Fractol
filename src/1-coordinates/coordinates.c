/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:42:59 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 10:46:57 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	reset_point(t_point *point)
{
	point->x = 0.0;
	point->y = 0.0;
}

void	reset_offset(t_axis *offset)
{
	offset->min = 0.0;
	offset->max = 0.0;
}

void	reset_x_and_y_offsets(t_axis *ofst_x, t_axis *ofst_y)
{
	reset_offset(ofst_x);
	reset_offset(ofst_y);
}
