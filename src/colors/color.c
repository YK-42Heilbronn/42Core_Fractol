/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:37:30 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 15:37:03 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	set_color_values(t_color *color, int r, int g, int b, int a)
{
	color->red = r;
	color->green = g;
	color->blue = b;
	color->alpha = a;
}

// #9cce32	(156,206,50)
// #f7b630	(247,182,48)
// #ffbbff	(255,187,255)
// #c6d8ff	(198,216,255)
// #00f7ff	(0,247,255)
void	initialize_color_palette_1(t_palette *c_palette)
{
	set_color_values(&(c_palette->color5), 156, 206, 50, 127);
	set_color_values(&(c_palette->color4), 247, 182, 48, 127);
	set_color_values(&(c_palette->color3), 255, 187, 255, 127);
	set_color_values(&(c_palette->color2), 198, 216, 255, 127);
	set_color_values(&(c_palette->color1), 0, 247, 255, 127);
}

// #f50d6b	(245,13,107)
// #c254ff	(194,84,255)
// #01a1ff	(1,161,255)
// #00c98e	(0,201,142)
// #032d4e	(3,45,78)
void	initialize_color_palette_2(t_palette *c_palette)
{
	set_color_values(&(c_palette->color3), 245, 13, 107, 127);
	set_color_values(&(c_palette->color4), 194, 84, 255, 127);
	set_color_values(&(c_palette->color1), 1, 161, 255, 127);
	set_color_values(&(c_palette->color2), 0, 201, 142, 127);
	set_color_values(&(c_palette->color5), 3, 45, 78, 127);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel_color(t_set_params *set_params)
{
	int	part;

	part = set_params->max_iters / 4;
	if (set_params->iter <= part)
		return (get_rgba(set_params->colors.color1.red,
				set_params->colors.color1.green,
				set_params->colors.color1.blue,
				set_params->colors.color1.alpha));
	else if (set_params->iter <= (part * 2))
		return (get_rgba(set_params->colors.color2.red,
				set_params->colors.color2.green,
				set_params->colors.color2.blue,
				set_params->colors.color2.alpha));
	else if (set_params->iter <= (part * 3))
		return (get_rgba(set_params->colors.color3.red,
				set_params->colors.color3.green,
				set_params->colors.color3.blue,
				set_params->colors.color3.alpha));
	else if (set_params->iter <= (part * 4))
		return (get_rgba(set_params->colors.color4.red,
				set_params->colors.color4.green,
				set_params->colors.color4.blue,
				set_params->colors.color4.alpha));
	else // if (set_params->iter <= set_params->max_iters)
	// @TODO: it wont go beyond max_iters yamini, you correct this logic
		return (get_rgba(set_params->colors.color5.red,
				set_params->colors.color5.green,
				set_params->colors.color5.blue,
				set_params->colors.color5.alpha));
}

uint32_t	get_vibrant_rgba(int gradient_value)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = (gradient_value * 2) % 256;
	green = (gradient_value * 3) % 256;
	blue = (gradient_value * 4) % 256;
	red = red / 2;
	green = green / 2;
	blue = blue / 2;
	alpha = 255;
	return (get_rgba(red, green, blue, alpha));
}
