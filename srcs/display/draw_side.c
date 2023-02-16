/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:33:24 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 10:44:29 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_transparant_pixel(t_data *data, int x, int y, int t_color)
{
	t_img	*img;
	char	*pixel;
	int		pixel_color;
	int		color;

	img = &data->img;
	color = t_color;
	pixel = img->data_addr + (y * img->size_l) + (x * (img->bpp / 8));
	if (pixel[R] != 0 || pixel[G] != 0 || pixel[B] != 0 || pixel[3] != 0)
	{
		if (img->endian == 0)
			pixel_color = rgb_color(pixel[B], pixel[G], pixel[R]);
		if (img->endian == 1)
			pixel_color = rgb_color(pixel[R + 1], pixel[G + 1], pixel[B + 1]);
		color = get_color(pixel_color, t_color, 100, 60);
	}
	draw_pixel(data, x, y, color);
}

void	draw_side(t_data *data)
{
	int	x;
	int	y;

	y = 10;
	while (y < 400)
	{
		x = 10;
		while (x < 250)
		{
			draw_transparant_pixel(data, x, y, GREY);
			x++;
		}
		y++;
	}
}
