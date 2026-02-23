/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:44:02 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 16:44:46 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
// initialize z(n) = 0+i*0 => 0
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
