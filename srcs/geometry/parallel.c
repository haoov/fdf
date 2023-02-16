/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:04:00 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 17:19:48 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_data *data)
{
	projection_matrix(data, 0.1, 1, 100);
	data->proj.zd = 10;
	data->proj.angle[Z] = 0;
	data->proj.angle[Y] = 0;
	data->proj.angle[X] = 270;
	display(data, data->map);
}
