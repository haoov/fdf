/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:30:35 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:38:34 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 						(r*f 0 0   0 )
projection matrix Mp =	( 0  f 0   0 )		q = Zf/(Zf-Zn)
						( 0  0 q Zn*q)
						( 0	 0 1   0 ) */

void	projection_matrix(t_data *data, double t, double zn, double zf)
{
	double	r;
	double	f;

	r = data->win.size.x / data->win.size.y;
	f = pow(tan((t * (M_PI / 180)) / 2), -1);
	data->matrix.proj[0][0] = r * f;
	data->matrix.proj[1][1] = f;
	data->matrix.proj[2][2] = zf / (zf - zn);
	data->matrix.proj[2][3] = (zf * zn) / (zf - zn);
	data->matrix.proj[3][2] = 1;
}
