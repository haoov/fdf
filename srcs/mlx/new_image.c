/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:11:51 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 13:12:19 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	new_image(t_data *data)
{
	if (data->img.id != NULL)
		mlx_destroy_image(data->mlx_id, data->img.id);
	data->img.id = mlx_new_image(data->mlx_id, data->win.size.x,
			data->win.size.y);
	if (data->win.id == NULL || data->img.id == NULL)
		return (EXIT_FAILURE);
	data->img.data_addr = mlx_get_data_addr(data->img.id,
			&data->img.bpp, &data->img.size_l, &data->img.endian);
	if (data->img.data_addr == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
