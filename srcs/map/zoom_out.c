/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:03:36 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 13:31:43 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_out(void *param, int x, int y)
{
	t_data	*data;
	t_vec2	vec;

	data = (t_data *)param;
	vec.x = x - data->map.origin.x;
	vec.y = y - data->map.origin.y;
	data->proj.t *= 2;
	if (data->proj.t > 10)
	{
		data->proj.t = 10;
		return (EXIT_FAILURE);
	}
	data->map.origin.x += vec.x / 2;
	data->map.origin.y += vec.y / 2;
	display(data, data->map);
	return (EXIT_SUCCESS);
}
