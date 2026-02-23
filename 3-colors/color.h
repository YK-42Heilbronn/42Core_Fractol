/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:35:00 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/23 15:45:54 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
// ===============
// Colors
// ===============
/*
2**32 colors possible ~ 4,294,967,296 (4Billion Colors)
*/
typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	int				alpha;
}					t_color;

// psychedelic colors
typedef struct s_palette
{
	t_color			color1;
	t_color			color2;
	t_color			color3;
	t_color			color4;
	t_color			color5;
}					t_palette;

#endif