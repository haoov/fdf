/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:47:15 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:47:16 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 						(SX 0  0  0)
scaling matrix Ms =		(0  SY 0  0)
						(0  0  SZ 0)
						(0  0  0  1) */

void	scaling_matrix(t_data *data, double sx, double sy, double sz)
{
	data->matrix.scale[0][0] = sx;
	data->matrix.scale[1][1] = sy;
	data->matrix.scale[2][2] = sz;
}
