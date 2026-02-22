/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:27:11 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/22 16:10:56 by ykonka           ###   ########.fr       */
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

// ===============
// Colors
// ===============
typedef struct s_color {
	int red;
	int green;
	int blue;
	int alpha;
} t_color;

// psychedelic colors
typedef struct s_palette {
	t_color color1;
	t_color color2;
	t_color color3;
	t_color color4;
	t_color color5;
} t_palette;

// ===============
// Complex Number
// ===============
typedef struct s_complex {
	double real;
	double imaginary;
} t_complex;

// ================
// Coordinate System & Their Elements
// ================
typedef struct s_axis {
	double min;
	double max;
} t_axis;

typedef struct s_point {
	double x;
	double y;
} t_point;

typedef struct s_plane {
	t_axis a_x;
	t_axis a_y;
	t_point pt;
	t_point offset;
	t_point cursor;
} t_plane;

// ===============
// Fractols
// ===============
typedef struct s_set_params {
	t_complex z;
	t_complex c;
	t_plane image;
	t_palette colors;
	int threshold;
	int iter;
	int max_iters;
	char *set;
	double *extras;
} t_set_params;

typedef struct s_fractol {
	mlx_image_t *img;
	mlx_t *mlx;
	t_plane window;
	t_set_params s_params;
} t_fractol;

// ===============
// Functions
// ===============
// fractol.c
void initialize_fractol(t_fractol *fractol);

// colors
void initialize_color_palette_1(t_palette *c_palette);
void initialize_color_palette_2(t_palette *c_palette);
int get_rgba(int r, int g, int b, int a);
int	get_pixel_color(t_set_params *set_params);
uint32_t	get_vibrant_rgba(int gradient_value);

// complex
double mod_cmplx_num(t_complex *num);
void squr_cmplx_num(t_complex *num);

// view_controls
// data.c
void update_image_axes_range(t_set_params *set_params);
void reset_offset_values(t_set_params *set_params);
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_closehook(void *mlx);
void my_resizehook(int32_t width, int32_t height, void *param);
void my_keyhook(mlx_key_data_t keydata, void *param);
void my_cursorhook(double xpos, double ypos, void* param);

// sets
// mandelbrot
void mandelbrot(t_fractol *frctl);

// julia
void julia(t_fractol *frctl);

// routines.c
void point_escaped_iteration_in_complex_plane(t_fractol *frctl);
void reset_z(t_set_params *set_params);
void update_z(t_set_params *set_params);

// coordinates_ops.c
double normalize_value(double crdnt_vlu, t_axis *ax, int max);
double min_max_diff(t_axis *ax);
double	transform_sys1_to_sys2(double crdnt_vlu, t_axis *sys1_ax, t_axis *sys2_ax);

// utils
// strtodouble.c
long	double	ft_strtod(char *str);

#endif