/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:46:01 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:46:02 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_matrix(t_data *data)
{
	data->matrix.trans[0][0] = 1;
	data->matrix.trans[1][1] = 1;
	data->matrix.trans[2][2] = 1;
	data->matrix.trans[3][3] = 1;
	data->matrix.scale[3][3] = 1;
	data->matrix.rot[X][0][0] = 1;
	data->matrix.rot[X][3][3] = 1;
	data->matrix.rot[Y][1][1] = 1;
	data->matrix.rot[Y][3][3] = 1;
	data->matrix.rot[Z][2][2] = 1;
	data->matrix.rot[Z][3][3] = 1;
	projection_matrix(data, data->proj.t, data->proj.zn, data->proj.zf);
}
