/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:42:46 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/01 16:42:47 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start(t_data *data)
{
	data->mlx_id = mlx_init();
	if (data->mlx_id == NULL)
		return (EXIT_FAILURE);
	data->win.id = mlx_new_window(data->mlx_id,
			data->win.size.x, data->win.size.y, "Fdf");
	if (new_image(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
