/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 07:37:15 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 10:02:02 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void initialize_complex(t_set_params *params)
{
	params->z.real = 0.0;
	params->z.imaginary = 0.0;

	// initialize x_axis of pixel and pattern
	params->plane_params.x.pixel_axis_limits[0] = 0;
	params->plane_params.x.pixel_axis_limits[1] = WIDTH;
	// params->plane_params.x.pattern_axis_limits[0] = -2.0;
	// params->plane_params.x.pattern_axis_limits[1] = 1.0;
	params->plane_params.x.pattern_axis_limits[0] = -2.5;
	params->plane_params.x.pattern_axis_limits[1] = 2.5;
	// initialize y_axis of pixel and pattern
	params->plane_params.y.pixel_axis_limits[0] = 0;
	params->plane_params.y.pixel_axis_limits[1] = HEIGHT;
	// params->plane_params.y.pattern_axis_limits[0] = -1.5;
	// params->plane_params.y.pattern_axis_limits[1] = 1.5;
	params->plane_params.y.pattern_axis_limits[1] = 1.5;
	params->plane_params.y.pattern_axis_limits[0] = -1.5;

	params->img_offset_x[0] = 0.0;
	params->img_offset_x[1] = 0.0;
	params->img_offset_y[0] = 0.0;
	params->img_offset_y[1] = 0.0;
	params->threshold = 16;
	params->max_iterations = 100;

	// color palette
	// initialize_color_palette_1(&(params->c_palette));
	initialize_color_palette_2(&(params->c_palette));
}

//-0.5125 + 0.5213i
void print_usage()
{
	char *print;

	print = "Usage: ./fractol [Mandelbrot(1) || Julia(2) [ca] [cb]]\n\
  e.g: ./fractol 1\n\
  e.g: ./fractol 2 -0.5125 0.5213\n";
	write(1, print, ft_strlen(print));
	exit(-1);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		print_usage();
	else
	{
		mlx_t *mlx;
		mlx_image_t *img;
		t_set_params set_params;
		int32_t *w;
		int32_t *h;
		char *set;

		mlx = mlx_init(WIDTH, HEIGHT, "", true);
		img = mlx_new_image(mlx, WIDTH, HEIGHT);

		// position window to center
		w = NULL;
		h = NULL;
		// mlx_get_monitor_size(0, w, h);
		// printf("%d - %d\n", *w, *h);
		// if (w != NULL && h != NULL)
		// 	mlx_set_window_pos(mlx, *w/4, *h/4);

		// mandelbrot
		initialize_complex(&set_params);
		set_params.img = img;
		set_params.mlx = mlx;
		if (argv[1][0] == '1' && argc == 2)
		{
			set = "Mandelbrot";
			mandelbrot(&set_params);
		}
		else if (argv[1][0] == '2' && argc == 4)
		{
			set = "Julia";
			julia(&set_params, ft_strtod(argv[2]), ft_strtod(argv[3]));
		}
		else
		{
			mlx_delete_image(mlx, img);
			mlx_close_window(mlx);
			print_usage();
		}
		mlx_image_to_window(mlx, img, 0, 0);
		mlx_set_window_title(mlx, set);
		mlx_scroll_hook(mlx, &my_scrollhook, &set_params);
		// mlx_close_hook(mlx, my_closehook, mlx);
		mlx_resize_hook(mlx, my_resizehook, &set_params);
		mlx_key_hook(mlx, my_keyhook, &set_params);
		// mlx_cursor_hook(mlx, my_cursorhook, &set_params);
		mlx_loop(mlx);
		// mlx_terminate(mlx);
	}
	return(0);
}