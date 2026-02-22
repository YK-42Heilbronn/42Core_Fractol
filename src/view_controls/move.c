/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:13:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 16:07:42 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// when close widget is pressed on titlebar, any cleans up must be done through following hook
void my_closehook(void *mlx)
{
	mlx_close_window(mlx);
	exit(0);
}

// resizing window simultaneously image
void my_resizehook(int32_t width, int32_t height, void *param)
{
	if (mlx_resize_image(((t_set_params*)param)->img, width, height))
		mandelbrot(param);
}


// close program if ESC key is pressed
void my_keyhook(mlx_key_data_t keydata, void *param)
{
	uint32_t width;
	uint32_t height;
	double offset;  // magnitude
	int forward;  // direction
	int backward;  // direction

	width = ((t_set_params*)param)->img->width;
	height = ((t_set_params*)param)->img->height;
	offset = 0.1;
	forward = 1;
	backward = -1;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(((t_set_params*)param)->mlx);

	// if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE)
	// {
	// 	((t_set_params*)param)->img_offset_x = 0.0;
	// 	((t_set_params*)param)->img_offset_y = 0.0;
	// 	mandelbrot(((t_set_params*)param)->img, width, height, param);
	// }
	reset_offset_values((t_set_params*)param);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		((t_set_params*)param)->img_offset_x[0] = offset*forward;
		((t_set_params*)param)->img_offset_x[1] = offset*forward;
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		((t_set_params*)param)->img_offset_x[0] = offset*backward;
		((t_set_params*)param)->img_offset_x[1] = offset*backward;
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		((t_set_params*)param)->img_offset_y[0] = offset*forward;
		((t_set_params*)param)->img_offset_y[1] = offset*forward;
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		((t_set_params*)param)->img_offset_y[0] = offset*backward;
		((t_set_params*)param)->img_offset_y[1] = offset*backward;
	}
	mandelbrot(param);

	// if 
}