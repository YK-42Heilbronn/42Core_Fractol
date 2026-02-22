/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:12:55 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 15:56:46 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void draw(t_fractol *frctl)
{
	frctl->window.pt.x = 0;
	while (frctl->window.pt.x < frctl->img->width)
	{
		frctl->window.pt.y = 0;
		while (frctl->window.pt.y < frctl->img->height)
		{
			frctl->s_params.c.real = transform_sys1_to_sys2(frctl->window.pt.x, \
				&(frctl->window.a_x), &(frctl->s_params.image.a_x));
			frctl->s_params.c.imaginary = transform_sys1_to_sys2(frctl->window.pt.y, \
				&(frctl->window.a_y), &(frctl->s_params.image.a_y));
			point_escaped_iteration_in_complex_plane(frctl);
			mlx_put_pixel(frctl->img, frctl->window.pt.x, frctl->window.pt.y, \
				get_pixel_color(&(frctl->s_params)));
			frctl->window.pt.y++;
			reset_z(&(frctl->s_params.z));
		}
		frctl->window.pt.x++;
	}
}

void mandelbrot(t_fractol *frctl)
{
	uint32_t color;
	uint32_t white;

	white = get_rgba(255, 0, 255, 221);
	color = get_rgba(0, 0, 255, 221);
	frctl->window.a_x.max = frctl->img->width;
	frctl->window.a_y.max = frctl->img->height;
	update_image_axes_range(&(frctl->s_params));
	draw(frctl);
}


