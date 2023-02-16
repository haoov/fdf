/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:31:55 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 16:56:15 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_data *data)
{
	projection_matrix(data, 0.1, 1, 100);
	data->proj.zd = 10;
	data->proj.angle[Z] = 30;
	data->proj.angle[Y] = 30;
	data->proj.angle[X] = 330;
	display(data, data->map);
}
