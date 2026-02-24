/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:41:01 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/24 08:13:22 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
