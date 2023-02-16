/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:45:04 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:45:05 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_color(unsigned char r, unsigned char g, unsigned char b)
{
	int	color;

	color = 0;
	color = ((r ^ 0) << 16) + ((g ^ 0) << 8) + (b ^ 0);
	return (color);
}
