/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:35:56 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/21 13:45:13 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// a + ib => sqrt(a*a + b*b)
double modulus_of_complex_number(t_complex *imag_num)
{
	return (sqrt(imag_num->real*imag_num->real+imag_num->imaginary*imag_num->imaginary));
}

/*
complex = a + ib;  i**2 = -1
complex**2 = (a+ib)*(a+ib)
		   =  aa + aib + iba + ibib
		   =  aa - bb + i2ab
*/
void square_of_complex_number(t_complex *imag_num)
{
	double temp_real;

	temp_real = (imag_num->real*imag_num->real) - (imag_num->imaginary*imag_num->imaginary);
	imag_num->imaginary = 2*imag_num->real*imag_num->imaginary;
	imag_num->real = temp_real;
}
