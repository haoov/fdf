/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:35:29 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:50:50 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COLORS_H
# define FDF_COLORS_H

# define R 0
# define G 1
# define B 2
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREY		0x202020

/*EARTH*/
# define RAINBOW_INDIGO	0x202361
# define DEEP_BLUE		0x000033
# define MIDDLE_GREEN	0x51885B
# define RIFLE_BROWN	0x4B443A
# define ALMOND			0xFDEDCF

/*MARS*/
# define CINEREOUS		0x99857A
# define DEER			0xC67B5C
# define TERRA_COTTA	0xE27B58
# define DARK_CHESTNUT	0xFF9D6F
# define EARTH_BROWN	0x663926

/*SPACE*/
# define OUTER_SPACE	0x303E42
# define DEEP_SPACE		0x182141
# define BLACK			0x232323
# define RAISIN_BLACK	0x232323
# define BLUE_SAPHIRE	0x89A7B9

typedef enum e_theme
{
	NONE,
	CLASSIC,
	SPACE,
	EARTH,
	MARS,
}t_theme;

typedef struct s_color
{
	t_theme	theme;
	int		bottom;
	int		under;
	int		ground;
	int		upper;
	int		top;
}t_color;

#endif