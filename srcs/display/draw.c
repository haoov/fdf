/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:03:01 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 11:23:20 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_from_up_left(t_data *data)
{
	t_point	**point;
	int		c;
	int		l;

	point = data->map.point;
	l = 0;
	while (l < data->map.size.y)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			if (c + 1 < data->map.size.x)
				draw_line(data, point[l][c], point[l][c + 1]);
			if (l + 1 < data->map.size.y)
				draw_line(data, point[l][c], point[l + 1][c]);
			c++;
		}
		l++;
	}
}

void	draw_from_up_right(t_data *data)
{
	t_point	**point;
	int		c;
	int		l;

	point = data->map.point;
	l = 0;
	while (l < data->map.size.y)
	{
		c = data->map.size.x - 1;
		while (c >= 0)
		{
			if (c - 1 >= 0)
				draw_line(data, point[l][c], point[l][c - 1]);
			if (l + 1 < data->map.size.y)
				draw_line(data, point[l][c], point[l + 1][c]);
			c--;
		}
		l++;
	}
}

void	draw_from_down_right(t_data *data)
{
	t_point	**point;
	int		c;
	int		l;

	point = data->map.point;
	l = data->map.size.y - 1;
	while (l >= 0)
	{
		c = data->map.size.x - 1;
		while (c >= 0)
		{
			if (c - 1 >= 0)
				draw_line(data, point[l][c], point[l][c - 1]);
			if (l - 1 >= 0)
				draw_line(data, point[l][c], point[l - 1][c]);
			c--;
		}
		l--;
	}
}

void	draw_from_down_left(t_data *data)
{
	t_point	**point;
	int		c;
	int		l;

	point = data->map.point;
	l = data->map.size.y - 1;
	while (l >= 0)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			if (c + 1 < data->map.size.x)
				draw_line(data, point[l][c], point[l][c + 1]);
			if (l - 1 >= 0)
				draw_line(data, point[l][c], point[l - 1][c]);
			c++;
		}
		l--;
	}
}

void	draw(t_data *data, t_point *starting_point)
{
	if (starting_point == data->map.corner[UP_LEFT])
		draw_from_up_left(data);
	else if (starting_point == data->map.corner[UP_RIGHT])
		draw_from_up_right(data);
	else if (starting_point == data->map.corner[DOWN_LEFT])
		draw_from_down_left(data);
	else if (starting_point == data->map.corner[DOWN_RIGHT])
		draw_from_down_right(data);
	draw_side(data);
}
