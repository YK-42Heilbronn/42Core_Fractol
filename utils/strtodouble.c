/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtodouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:14:43 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:43:39 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long double	ft_atold(const char *str)
{
	int			minus;
	long double	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == 45 || *str == 43)
	{
		minus = 44 - *str;
		str++;
	}
	while (*str)
	{
		if (*str < 48 && *str > 57)
			exit(-1);
		result = (result * 10.0) + (*str++ - 48);
	}
	return (result * minus);
}

void	free2d_arr(char **arr2d)
{
	char	**tmp;

	if (!arr2d)
		return ;
	tmp = arr2d;
	while (*arr2d)
	{
		free(*arr2d);
		arr2d++;
	}
	free(tmp);
}

void	handle_decimal_part(const char *decimal_str, long double *result,
		const char *integer_str, long double *integer_num)
{
	double	decimal_num;
	int		sign;
	int		zeros;

	sign = 1;
	decimal_num = ft_atold(decimal_str);
	zeros = ft_strlen(decimal_str);
	while (zeros-- > 0)
		decimal_num = decimal_num / 10.0;
	if (integer_str[0] == '-')
		sign = -1;
	if (sign < 0)
	{
		*result = ((*integer_num) * sign) + decimal_num;
		*result = (*result) * sign;
	}
	else
		*result = *integer_num + decimal_num;
}

long double	ft_strtod(char *str)
{
	char		**str_split;
	long double	integer_num;
	long double	result;
	char		*str_trim;

	str_trim = ft_strtrim(str, " \t\f\n\r\v");
	if (!str_trim)
		exit(-1);
	str_split = ft_split(str_trim, '.');
	free(str_trim);
	if (!str_split)
		exit(-1);
	integer_num = ft_atold(str_split[0]);
	if (str_split[1])
		handle_decimal_part(str_split[1], &result, str_split[0], &integer_num);
	else
		result = integer_num;
	free2d_arr(str_split);
	return (result);
}
