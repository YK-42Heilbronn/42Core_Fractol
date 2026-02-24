/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:44:02 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 10:26:48 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	display_set(t_fractol *frctl)
{
	if (frctl->s_params.set[0] == '1')
		mandelbrot(frctl);
	else if (frctl->s_params.set[0] == '2')
		julia(frctl);
	else
		mandelbrot(frctl);
}

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

void	point_escaped_iteration_in_complex_plane(t_fractol *frctl)
{
	frctl->s_params.iter = 1;
	while (frctl->s_params.iter <= frctl->s_params.max_iters)
	{
		update_z(&(frctl->s_params));
		if (mod_cmplx_num(&(frctl->s_params.z)) > frctl->s_params.threshold)
			break ;
		frctl->s_params.iter++;
	}
}

// z(n+1) = z(n)**2 + c
void	update_z(t_set_params *set_params)
{
	squr_cmplx_num(&(set_params->z));
	set_params->z.real = set_params->z.real + set_params->c.real;
	set_params->z.imaginary = set_params->z.imaginary + set_params->c.imaginary;
}

void	reset_z(t_complex *z)
{
	z->real = 0.0;
	z->imaginary = 0.0;
}
