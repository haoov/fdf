/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:21:11 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:55:09 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* rotation matrix 
						(1   0	    0	  0)			(cos(t)  0 sin(t) 0)			(cos(t) -sin(t) 0 0)
				Mrx =	(0 cos(t) -sin(t) 0)	Mry = 	(  0	 1   0	  0)	Mrz =	(sin(t) cos(t)	0 0)
						(0 sin(t) cos(t)  0)			(-sin(t) 0 cos(t) 0)			(  0	  0		1 0)
						(0   0	    0	  1)			(  0	 0   0	  1)			(  0	  0		0 1)
*/

void	rotation_matrix(t_data *data, double a, int axe)
{
	double	t;

	t = a * (M_PI / 180);
	if (axe == X)
	{
		data->matrix.rot[X][1][1] = cos(t);
		data->matrix.rot[X][1][2] = -sin(t);
		data->matrix.rot[X][2][1] = sin(t);
		data->matrix.rot[X][2][2] = cos(t);
	}
	else if (axe == Y)
	{
		data->matrix.rot[Y][0][0] = cos(t);
		data->matrix.rot[Y][0][2] = sin(t);
		data->matrix.rot[Y][2][0] = -sin(t);
		data->matrix.rot[Y][2][2] = cos(t);
	}
	else if (axe == Z)
	{
		data->matrix.rot[Z][0][0] = cos(t);
		data->matrix.rot[Z][0][1] = -sin(t);
		data->matrix.rot[Z][1][0] = sin(t);
		data->matrix.rot[Z][1][1] = cos(t);
	}
}
