/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_corners.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:22 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 15:50:03 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_corners(t_data *data)
{
	int	x_max;
	int	y_max;

	x_max = data->map.size.x - 2;
	y_max = data->map.size.y - 1;
	data->map.corner[UP_LEFT] = &data->map.point[0][0];
	data->map.corner[UP_RIGHT] = &data->map.point[0][x_max];
	data->map.corner[DOWN_LEFT] = &data->map.point[y_max][0];
	data->map.corner[DOWN_RIGHT] = &data->map.point[y_max][x_max];
}
