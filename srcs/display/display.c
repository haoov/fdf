/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:15:24 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 16:11:51 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*starting_point(t_data *data)
{
	t_point	**corner;
	double	dist_max;
	int		i;

	corner = data->map.corner;
	dist_max = max((*corner[UP_LEFT]).proj.z, (*corner[UP_RIGHT]).proj.z);
	dist_max = max(dist_max,
			max((*corner[DOWN_LEFT]).proj.z, (*corner[DOWN_RIGHT]).proj.z));
	i = 0;
	while (i < 3)
	{
		if (dist_max == (*corner[i]).proj.z)
			break ;
		i++;
	}
	return (corner[i]);
}

int	display(t_data *data, t_map map)
{
	(void)map;
	new_image(data);
	init_proj(data, data->map);
	mvp(data);
	draw(data, starting_point(data));
	mlx_put_image_to_window(data->mlx_id, data->win.id, data->img.id, 0, 0);
	draw_menu(data);
	return (EXIT_SUCCESS);
}
