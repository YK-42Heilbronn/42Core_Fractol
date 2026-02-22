/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:41:01 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/21 13:45:18 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// double normalize_value(double value, double axis_limits[2], int min)
// 							equivalent-to
double normalize_value(double value, double *axis_limits, int max)
{
	if (!max)
		return ((value - axis_limits[0]) / (axis_limits[1] - axis_limits[0]));
	else
		return ((value - axis_limits[1]) / (axis_limits[1] - axis_limits[0]));
}

double min_max_diff(double *axis_limits[2])
{
	return (*axis_limits[1] - *axis_limits[0]);
}

// https://stackoverflow.com/questions/929103/convert-a-number-range-to-another-range-maintaining-ratio#:~:text=That's%20a%20simple%20linear%20conversion,627k169%20923%20945
double transform_pixels_to_pattern_coordinates(double pixel_value, t_transform_axis *axis_params)
{
	// 0:min, 1:max
	// double pixel_axis[2];  // old
	// double pattern_axis[2] // new
	double new_value;
	new_value = (pixel_value - axis_params->pixel_axis_limits[0])/
	(axis_params->pixel_axis_limits[1] - axis_params->pixel_axis_limits[0]);
	new_value = new_value * (axis_params->pattern_axis_limits[1] -
		axis_params->pattern_axis_limits[0]);
	new_value = new_value + axis_params->pattern_axis_limits[0];
	return new_value;
}
