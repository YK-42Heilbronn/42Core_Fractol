/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:37:30 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 14:36:11 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_gradient(t_set_params *set_params)
{
	int value;

	value = ((set_params->iter * 255) / set_params->max_iters);
	return (value);
}

// Yellow= get_rgba(grad, grad, (grad*255)%255, 221)
// Green= get_rgba((grad*2)%255, grad, (grad*8)%255, 221)
// Red= get_rgba(grad, (grad*255)%255, (grad*255)%255, 221)
// Purple= get_rgba(grad, (grad*255)%255, grad, 221)
// Blue= get_rgba((grad*255)%255, (grad*255)%255, grad, 221)
// White= get_rgba(grad, grad, grad, 221)
uint32_t	get_simple_coloring(int grad)
{
	return get_rgba((grad*255)%255, (grad*255)%255, grad, 221);
}

uint32_t 	get_band_coloring(int grad)
{
	return get_rgba((grad*2)%255, 0, (grad*8)%255, 221);
}

uint32_t	get_continuous_coloring(t_set_params *s_params)
{
	int color;

	color = log(\
		mod_cmplx_num(&(s_params->z)) / \
		pow(2, get_color_gradient(s_params)));
	return get_rgba(color, 0, 0, 221);
}
