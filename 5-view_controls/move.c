/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:13:10 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 08:15:14 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	close_program(void *mlx)
{
	mlx_close_window(mlx);
}

void	resize_view(int32_t width, int32_t height, void *frctl)
{
	if (mlx_resize_image(((t_fractol *)frctl)->img, width, height))
		display_set((t_fractol *)frctl);
}

static void	arrow_keys(mlx_key_data_t *keydata, void *frctl)
{
	t_set_params	*s_params;
	t_view_params	*v_params;

	s_params = &((t_fractol *)frctl)->s_params;
	v_params = &((t_fractol *)frctl)->v_params;
	if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_RELEASE)
	{
		s_params->image.offset_x.min = v_params->offset * v_params->forward;
		s_params->image.offset_x.max = v_params->offset * v_params->forward;
	}
	else if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_RELEASE)
	{
		s_params->image.offset_x.min = v_params->offset * v_params->backward;
		s_params->image.offset_x.max = v_params->offset * v_params->backward;
	}
	else if (keydata->key == MLX_KEY_UP && keydata->action == MLX_RELEASE)
	{
		s_params->image.offset_y.min = v_params->offset * v_params->forward;
		s_params->image.offset_y.max = v_params->offset * v_params->forward;
	}
	else if (keydata->key == MLX_KEY_DOWN && keydata->action == MLX_RELEASE)
	{
		s_params->image.offset_y.min = v_params->offset * v_params->backward;
		s_params->image.offset_y.max = v_params->offset * v_params->backward;
	}
}

/*
following events are handled:
	- CLOSE program if ESC key is pressed
	- MOVE view if ARROW keys are pressed
*/
void	inputs_events(mlx_key_data_t keydata, void *frctl)
{
	t_set_params	*s_params;

	s_params = &((t_fractol *)frctl)->s_params;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(((t_fractol *)frctl)->mlx);
	reset_x_and_y_offsets(&(s_params->image.offset_x),
		&(s_params->image.offset_y));
	arrow_keys(&keydata, frctl);
	display_set(frctl);
}
