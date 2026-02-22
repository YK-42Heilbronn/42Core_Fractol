/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:12:55 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/21 14:06:01 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// z(n+1) = z(n)**2 + c
// initialize z(n) = 0+i*0 => 0
void update_z(t_set_params *set_params)
{
	square_of_complex_number(&(set_params->z));
	set_params->z.real = set_params->z.real + set_params->c.real;
	set_params->z.imaginary = set_params->z.imaginary + set_params->c.imaginary;

}

void reset_z(t_set_params *set_params)
{
	set_params->z.real = 0.0;
	set_params->z.imaginary = 0.0;
}

void update_pattern_coordinates_limites(t_set_params *set_params)
{
	// coordinate - x
	set_params->plane_params.x.pattern_axis_limits[0] = set_params->plane_params.x.pattern_axis_limits[0] + 
														set_params->img_offset_x[0];  // shrinking/expanding from min x coordinate(which is -ve)
	set_params->plane_params.x.pattern_axis_limits[1] = set_params->plane_params.x.pattern_axis_limits[1] + 
														set_params->img_offset_x[1];  // shrinking/expanding from max x coordinate(which is +ve)
	// coordinate - y
	set_params->plane_params.y.pattern_axis_limits[0] = set_params->plane_params.y.pattern_axis_limits[0] + 
														set_params->img_offset_y[0];  // shrinking/expanding from min y coordinate(which is -ve)
	set_params->plane_params.y.pattern_axis_limits[1] = set_params->plane_params.y.pattern_axis_limits[1] + 
														set_params->img_offset_y[1]; // shrinking/expanding from max y coordinate(which is +ve)
}

static void draw(t_set_params *set_params)
{
	double x_a;
	double y_b;
		int iteration;

	x_a = 0;
	while (x_a < set_params->img->width)
	{
		y_b = 0;
		while (y_b < set_params->img->height)
		{
			set_params->c.real = transform_pixels_to_pattern_coordinates(x_a, &(set_params->plane_params.x));
			set_params->c.imaginary = transform_pixels_to_pattern_coordinates(y_b, &(set_params->plane_params.y));
			iteration = 0;
			while (iteration < set_params->max_iterations)
			{
				update_z(set_params);
				if (modulus_of_complex_number(&(set_params->z)) > set_params->threshold)
					break;
				iteration++;
			}
			mlx_put_pixel(set_params->img, x_a, y_b, get_pixel_color(set_params, iteration));
			y_b++;
			reset_z(set_params);
		}
		x_a++;
	}
}

void mandelbrot(t_set_params *set_params)
{
	uint32_t color;
	uint32_t white;

	white = get_rgba(255, 0, 255, 221);
	color = get_rgba(0, 0, 255, 221);
	set_params->plane_params.x.pixel_axis_limits[1] = set_params->img->width;
	set_params->plane_params.y.pixel_axis_limits[1] = set_params->img->height;
	update_pattern_coordinates_limites(set_params);
	draw(set_params);
}


