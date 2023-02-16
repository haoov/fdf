/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:28:47 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 11:28:48 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	model(t_data *data)
{
	t_map	map;

	map = data->map;
	translation_matrix(data, -(map.size.x / 2), -(map.size.y / 2), 0);
	scaling_matrix(data, 1, 1, pow(data->proj.zd, -1));
	combine_matrix(data->matrix.mv, data->matrix.trans, data->matrix.scale);
	apply_matrix(data, data->matrix.mv);
}

void	transformation(t_data *data)
{
	rotation_matrix(data, data->proj.angle[Z], Z);
	rotation_matrix(data, data->proj.angle[Y], Y);
	rotation_matrix(data, data->proj.angle[X], X);
	combine_matrix(data->matrix.mv, data->matrix.rot[Z], data->matrix.rot[Y]);
	combine_matrix(data->matrix.mv, data->matrix.mv, data->matrix.rot[X]);
	apply_matrix(data, data->matrix.mv);
}

void	view(t_data *data)
{
	translation_matrix(data, 0, 0, data->proj.zt);
	apply_matrix(data, data->matrix.trans);
}

void	projection(t_data *data)
{
	projection_matrix(data, data->proj.t, data->proj.zn, data->proj.zf);
	apply_matrix(data, data->matrix.proj);
}

void	mvp(t_data *data)
{
	model(data);
	transformation(data);
	view(data);
	projection(data);
}
