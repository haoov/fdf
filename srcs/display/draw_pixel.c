/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:31 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/01 16:03:56 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	t_img	*img;
	char	*pixel;

	img = &data->img;
	if (img->bpp != 32)
		color = mlx_get_color_value(data->mlx_id, color);
	pixel = img->data_addr + (y * img->size_l) + (x * (img->bpp / 8));
	if (img->endian == 0)
	{
		pixel[0] = (color >> 0) & 0xFF;
		pixel[1] = (color >> 8) & 0xFF;
		pixel[2] = (color >> 16) & 0xFF;
		pixel[3] = (color >> 24) & 0xFF;
	}
	else if (img->endian == 1)
	{
		pixel[0] = (color >> 24) & 0xFF;
		pixel[1] = (color >> 16) & 0xFF;
		pixel[2] = (color >> 8) & 0xFF;
		pixel[3] = (color >> 0) & 0xFF;
	}
}
