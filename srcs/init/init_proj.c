/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:44:16 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 13:02:08 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	z_min(t_map map)
{
	int		l;
	int		c;
	double	z_min;

	z_min = map.point[0][0].proj.z;
	l = 0;
	while (l < map.size.y)
	{
		c = 0;
		while (c < map.size.x)
		{
			if (map.point[l][c].proj.z < z_min)
				z_min = map.point[l][c].proj.z;
			c++;
		}
		l++;
	}
	return (z_min);
}

static double	z_max(t_map map)
{
	int		l;
	int		c;
	double	z_max;

	z_max = map.point[0][0].proj.z;
	l = 0;
	while (l < map.size.y)
	{
		c = 0;
		while (c < map.size.x)
		{
			if (map.point[l][c].proj.z > z_max)
				z_max = map.point[l][c].proj.z;
			c++;
		}
		l++;
	}
	return (z_max);
}

void	init_proj(t_data *data, t_map map)
{
	const double	diag = sqrt(pow(map.size.x, 2) + pow(map.size.y, 2));
	int				l;
	int				c;

	data->proj.zr = z_max(map) - z_min(map);
	data->proj.zt = max(diag, data->proj.zr);
	l = 0;
	while (l < map.size.y)
	{
		c = 0;
		while (c < map.size.x)
		{
			map.point[l][c].proj.x = map.point[l][c].cdt.x;
			map.point[l][c].proj.y = map.point[l][c].cdt.y;
			map.point[l][c].proj.z = map.point[l][c].cdt.z;
			map.point[l][c].proj.w = map.point[l][c].cdt.w;
			c++;
		}
		l++;
	}
}
