/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:27:11 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 10:14:32 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libs/MLX42/include/MLX42/MLX42.h"
# include "./libs/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

/*
2**32 colors possible ~ 4,294,967,296 (4Billion Colors)
*/
# define WIDTH 1024
# define HEIGHT 768

typedef struct s_complex {
	double real;
	double imaginary;
} t_complex;

typedef struct s_transform_axis {
	double pixel_axis_limits[2];
	double pattern_axis_limits[2];
} t_transform_axis;

typedef struct s_transform_plane {
	t_transform_axis x;
	t_transform_axis y;
} t_transform_plane;

typedef struct s_color {
	int red;
	int green;
	int blue;
	int alpha;
} t_color;

typedef struct s_psychedelic_palette {
	t_color color1;
	t_color color2;
	t_color color3;
	t_color color4;
	t_color color5;
} t_psychedelic_palette;

typedef struct s_set_params {
	mlx_image_t *img;
	mlx_t *mlx;
	t_complex z;
	t_complex c;
	t_transform_plane plane_params;
	t_psychedelic_palette c_palette;
	double img_offset_x[2];
	double img_offset_y[2];
	double cursor_x;
	double cursor_y;
	int threshold;
	int max_iterations;
} t_set_params;

typedef struct s_fractol {
	mlx_image_t *img;
	mlx_t *mlx;
	double img_offset_x[2];
	double img_offset_y[2];
	double img_cursor_x;
	double img_cursor_y;
	t_set_params *set_params;
} t_fractol;

// colors
void initialize_color_palette_1(t_psychedelic_palette *c_palette);
void initialize_color_palette_2(t_psychedelic_palette *c_palette);
int get_rgba(int r, int g, int b, int a);
int get_pixel_color(t_set_params *set_params, int iteration);
uint32_t	get_vibrant_rgba(int gradient_value);

// complex
double modulus_of_complex_number(t_complex *imag_num);
void square_of_complex_number(t_complex *imag_num);

// view_controls
// hooks.c
void reset_offset_values(t_set_params *set_params);
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_closehook(void *mlx);
void my_resizehook(int32_t width, int32_t height, void *param);
void my_keyhook(mlx_key_data_t keydata, void *param);
void my_cursorhook(double xpos, double ypos, void* param);

// transformation.c
double normalize_value(double value, double *axis_limits, int max);
double min_max_diff(double *axis_limits[2]);
double transform_pixels_to_pattern_coordinates(double pixel_value, t_transform_axis *axis_params);

// sets
// mandelbrot
void reset_z(t_set_params *set_params);
void update_z(t_set_params *set_params);
void update_pattern_coordinates_limites(t_set_params *set_params);
void mandelbrot(t_set_params *set_params);

// julia
void julia(t_set_params *set_params, double ca, double cb);

// utils
long	double	ft_strtod(char *str);

#endif