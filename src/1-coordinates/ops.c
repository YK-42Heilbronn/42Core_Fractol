/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:41:01 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:47:49 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// double normalize_value(double value, double axis_limits[2], int min)
// 							equivalent-to
double	normalize_value(double crdnt_vlu, t_axis *ax, int max)
{
	if (max)
		return ((ax->max - crdnt_vlu) / min_max_diff(ax));
	else
		return ((crdnt_vlu - ax->min) / min_max_diff(ax));
}

double	min_max_diff(t_axis *ax)
{
	return (ax->max - ax->min);
}

/*
@Ref:: [https://stackoverflow.com/questions/929103/convert-a-number-range-to-
another-range-maintaining-ratio#:~:text=That's%20a%20simple%20linear%20
conversion,627k169%20923%20945]
scaling-factor       =  value - x_old[min] / x_old[max]
	- x_old[min]        :: old system factor abstraction
translation          =  scaling-factor * x_new[max]
	- x_new[min]            :: old -> new
transformed-value    =  translation
	+ x_new[min];                           :: positioning in new
coordinate-value     => crdnt_vlu
system1-axis         => sys1_ax
system2-axis         => sys2_ax
*/
double	transform_sys1_to_sys2(double crdnt_vlu, t_axis *sys1_ax,
		t_axis *sys2_ax)
{
	double	sclng_fctr;
	double	translation;
	double	trsfd_vlu;

	sclng_fctr = normalize_value(crdnt_vlu, sys1_ax, 0);
	translation = sclng_fctr * min_max_diff(sys2_ax);
	trsfd_vlu = translation + sys2_ax->min;
	return (trsfd_vlu);
}
