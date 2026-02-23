/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:35:56 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:42:19 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// a + ib => sqrt(a*a + b*b)
double	mod_cmplx_num(t_complex *num)
{
	return (sqrt((num->real * num->real) + (num->imaginary * num->imaginary)));
}

/*
complex = a + ib;  i**2 = -1
complex**2 = (a+ib)*(a+ib)
			=  aa + aib + iba + ibib
			=  aa - bb + i2ab
*/
void	squr_cmplx_num(t_complex *num)
{
	double	temp_real;

	temp_real = (num->real * num->real) - (num->imaginary * num->imaginary);
	num->imaginary = 2 * num->real * num->imaginary;
	num->real = temp_real;
}
