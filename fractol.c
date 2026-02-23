/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 07:37:15 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:41:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_fractol(t_fractol *frctl)
{
	frctl->s_params.z.real = 0.0;
	frctl->s_params.z.imaginary = 0.0;
	frctl->s_params.image.a_x.min = -2.5;
	frctl->s_params.image.a_x.max = 2.5;
	frctl->s_params.image.a_y.min = -1.5;
	frctl->s_params.image.a_y.max = 1.5;
	frctl->s_params.threshold = 16;
	frctl->s_params.iter = 0;
	frctl->s_params.max_iters = 100;
	frctl->s_params.extras = NULL;
	frctl->window.a_x.min = 0;
	frctl->window.a_x.max = WIDTH;
	frctl->window.a_y.min = 0;
	frctl->window.a_y.max = HEIGHT;
	frctl->v_params.offset = 0.1;
	frctl->v_params.forward = 1;
	frctl->v_params.backward = -1;
}

void	print_usage(void)
{
	char	*print;

	print = "Usage: ./fractol [(1)Mandelbrot]\
 || [(2)Julia [(ca)real] [(cb)imaginary]]\n\
  e.g: ./fractol 1\n\
  e.g: ./fractol 2\n\
  e.g: ./fractol 2 -0.5125 0.5213\n";
	write(1, print, ft_strlen(print));
	exit(-1);
}

void	display_set(t_fractol *frctl)
{
	if (frctl->s_params.set[0] == '1')
		mandelbrot(frctl);
	else if (frctl->s_params.set[0] == '2')
		julia(frctl);
	else
		mandelbrot(frctl);
}

void	validate_argvs(int argc, char *argv[], t_fractol *frctl)
{
	if (argc <= 1)
		print_usage();
	else
	{
		if (argv[1][0] == '1' && argc == 2)
			frctl->s_params.set = "1-Mandelbrot";
		else if (argv[1][0] == '2' && (argc == 2 || argc == 4))
		{
			frctl->s_params.set = "2-Julia";
			if (argc == 4)
			{
				frctl->s_params.c.real = ft_strtod(argv[2]);
				frctl->s_params.c.imaginary = ft_strtod(argv[3]);
			}
			if (argc == 2)
			{
				frctl->s_params.c.real = -0.5125;
				frctl->s_params.c.imaginary = 0.5213;
			}
		}
		else
			print_usage();
	}
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	frctl;

	validate_argvs(argc, argv, &frctl);
	mlx = mlx_init(WIDTH, HEIGHT, "", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	initialize_fractol(&frctl);
	frctl.img = img;
	frctl.mlx = mlx;
	mlx_image_to_window(mlx, img, 0, 0);
	display_set(&frctl);
	mlx_set_window_title(mlx, frctl.s_params.set);
	mlx_scroll_hook(mlx, &zoom_view, &frctl);
	mlx_resize_hook(mlx, &resize_view, &frctl);
	mlx_key_hook(mlx, &inputs_events, &frctl);
	mlx_close_hook(mlx, &close_program, mlx);
	mlx_loop(mlx);
	return (0);
}
