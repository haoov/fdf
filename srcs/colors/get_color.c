/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:51:57 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/30 19:08:46 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define C1 0
#define C2 1
#define NC 2

void	get_rgb(int c1, int c2, unsigned char rgb[3][3])
{
	rgb[C1][R] = (c1 >> 16) & 0xFF;
	rgb[C1][G] = (c1 >> 8) & 0xFF;
	rgb[C1][B] = (c1) & 0xFF;
	rgb[C2][R] = (c2 >> 16) & 0xFF;
	rgb[C2][G] = (c2 >> 8) & 0xFF;
	rgb[C2][B] = (c2) & 0xFF;
}

int	get_color(int c1, int c2, int grad, int step)
{
	int				new_color;
	double			c_grad[3];
	unsigned char	rgb[3][3];

	get_rgb(c1, c2, rgb);
	c_grad[R] = fabs((double)((rgb[C1][R] - rgb[C2][R])) / grad);
	c_grad[G] = fabs((double)((rgb[C1][G] - rgb[C2][G])) / grad);
	c_grad[B] = fabs((double)((rgb[C1][B] - rgb[C2][B])) / grad);
	if (rgb[C1][R] < rgb[C2][R])
		rgb[NC][R] = rgb[C1][R] + (step * c_grad[R]);
	else
		rgb[NC][R] = rgb[C1][R] - (step * c_grad[R]);
	if (rgb[C1][G] < rgb[C2][G])
		rgb[NC][G] = rgb[C1][G] + (step * c_grad[G]);
	else
		rgb[NC][G] = rgb[C1][G] - (step * c_grad[G]);
	if (rgb[C1][B] < rgb[C2][B])
		rgb[NC][B] = rgb[C1][B] + (step * c_grad[B]);
	else
		rgb[NC][B] = rgb[C1][B] - (step * c_grad[B]);
	new_color = rgb_color(rgb[NC][R], rgb[NC][G], rgb[NC][B]);
	return (new_color);
}
