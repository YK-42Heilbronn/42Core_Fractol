/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:27:11 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 08:16:15 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libs/MLX42/include/MLX42/MLX42.h"
# include "./libs/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 768
// ===============
// Complex Number
// ===============
typedef struct s_complex
{
	double			real;
	double			imaginary;
}					t_complex;

// ================
// Coordinate System
// ================
typedef struct s_axis
{
	double			min;
	double			max;
}					t_axis;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_plane
{
	t_axis			a_x;
	t_axis			a_y;
	t_axis			offset_x;
	t_axis			offset_y;
	t_point			pt;
	t_point			cursor;
}					t_plane;

// ===============
// Fractols
// ===============
typedef struct s_set_params
{
	t_complex		z;
	t_complex		c;
	t_plane			image;
	int				threshold;
	int				iter;
	int				max_iters;
	char			*set;
	double			*extras;
}					t_set_params;

/*
offset   ->  magnitude
forward  ->  direction
backward ->  direction
*/
typedef struct s_view_params
{
	double			offset;
	int				forward;
	int				backward;
	int				zoom;
}					t_view_params;

typedef struct s_fractol
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_plane			window;
	t_set_params	s_params;
	t_view_params	v_params;
}					t_fractol;

// ===============
// Methods
// ===============
// fractol.c
void				initialize_fractol(t_fractol *fractol);
void				display_set(t_fractol *frctl);

// colors
int					get_rgba(int r, int g, int b, int a);
int					get_color_gradient(t_set_params *set_params);
uint32_t			get_simple_coloring(int grad);
uint32_t			get_band_coloring(int grad);
uint32_t			get_continuous_coloring(t_set_params *s_params);

// complex
double				mod_cmplx_num(t_complex *num);
void				squr_cmplx_num(t_complex *num);

// view_controls
// data.c
void				update_image_axes_range(t_set_params *set_params);
void				cursor_data(double xpos, double ypos, void *frctl);

// move.c
void				close_program(void *mlx);
void				resize_view(int32_t width, int32_t height, void *frctl);
void				inputs_events(mlx_key_data_t keydata, void *frctl);

// zoom.c
void				zoom_view(double xdelta, double ydelta, void *frctl);

// sets
// mandelbrot
void				mandelbrot(t_fractol *frctl);

// julia
void				julia(t_fractol *frctl);

// routines.c
void				point_escaped_iteration_in_complex_plane(t_fractol *frctl);
void				reset_z(t_complex *z);
void				update_z(t_set_params *set_params);

// coordinates
// ops.c
double				normalize_value(double crdnt_vlu, t_axis *ax, int max);
double				min_max_diff(t_axis *ax);
double				transform_sys1_to_sys2(double crdnt_vlu, t_axis *sys1_ax,
						t_axis *sys2_ax);

// coordinates.c
void				reset_point(t_point *point);
void				reset_offset(t_axis *offset);
void				reset_x_and_y_offsets(t_axis *ofst_x, t_axis *ofst_y);

// utils
// strtodouble.c
long double			ft_strtod(char *str);

#endif