/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:46:49 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 13:29:54 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_in(void *param, int x, int y)
{
	t_data	*data;
	t_vec2	vec;

	(void)x;
	(void)y;
	data = (t_data *)param;
	vec.x = x - data->map.origin.x;
	vec.y = y - data->map.origin.y;
	data->proj.t /= 2;
	if (data->proj.t < 0.005)
	{
		data->proj.t = 0.005;
		return (EXIT_FAILURE);
	}
	data->map.origin.x += -vec.x;
	data->map.origin.y += -vec.y;
	display(data, data->map);
	return (EXIT_SUCCESS);
}
