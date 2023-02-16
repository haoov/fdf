/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_theme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:44:43 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:44:44 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_height(t_data *data)
{
	int		min;
	int		l;
	int		c;

	min = data->map.point[0][0].height;
	l = 0;
	while (l < data->map.size.y)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			if (data->map.point[l][c].height < min)
				min = data->map.point[l][c].height;
			c++;
		}
		l++;
	}
	return (min);
}

int	max_height(t_data *data)
{
	int		max;
	int		l;
	int		c;

	max = data->map.point[0][0].height;
	l = 0;
	while (l < data->map.size.y)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			if (data->map.point[l][c].height > max)
				max = data->map.point[l][c].height;
			c++;
		}
		l++;
	}
	return (max);
}

void	change_color(t_color color, t_point *p, int max, int min)
{
	if (p->height == min && p->height != 0)
		p->color = color.bottom;
	else if (p->height == 0)
		p->color = color.ground;
	else if (p->height == max && p->height != 0)
		p->color = color.top;
	else if (p->height > min && p->height <= min / 2)
		p->color = get_color(color.under, color.bottom,
				min / 2, -(p->height) + min / 2);
	else if (p->height > min / 2 && p->height < 0)
		p->color = get_color(color.ground, color.under, min / 2, -p->height);
	else if (p->height > 0 && p->height < max / 2)
		p->color = get_color(color.ground, color.upper, max / 2, p->height);
	else if (p->height >= max / 2)
		p->color = get_color(color.upper, color.top,
				max / 2, p->height - max / 2);
}

void	apply_theme(t_data *data)
{
	int	c;
	int	l;
	int	max;
	int	min;

	max = max_height(data);
	min = min_height(data);
	l = 0;
	while (l < data->map.size.y)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			change_color(data->map.color, &data->map.point[l][c], max, min);
			c++;
		}
		l++;
	}
}
