/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:27 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 19:31:49 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_pts(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		free(map->point[y]);
		y++;
	}
	free(map->point);
}

void	exit_prg(t_data *data, char *msg, int exit_code)
{
	if (data->map.corner != NULL)
		free(data->map.corner);
	if (data->map.name != NULL)
		free(data->map.name);
	if (data->map.point != NULL)
		free_pts(&data->map);
	if (data->img.id != NULL)
		mlx_destroy_image(data->mlx_id, data->img.id);
	if (data->win.id != NULL)
		mlx_destroy_window(data->mlx_id, data->win.id);
	if (data->mlx_id != NULL)
	{
		mlx_destroy_display(data->mlx_id);
		free(data->mlx_id);
	}
	if (exit_code == EXIT_FAILURE)
		return (error(msg));
	exit(EXIT_SUCCESS);
}
