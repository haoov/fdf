/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:30:18 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 11:23:37 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_cdt(t_point *p, double m[4][4])
{
	double	xt;
	double	yt;
	double	zt;
	double	wt;

	xt = p->proj.x;
	yt = p->proj.y;
	zt = p->proj.z;
	wt = p->proj.w;
	p->proj.x = xt * m[0][0] + yt * m[0][1] + zt * m[0][2] + wt * m[0][3];
	p->proj.y = xt * m[1][0] + yt * m[1][1] + zt * m[1][2] + wt * m[1][3];
	p->proj.z = xt * m[2][0] + yt * m[2][1] + zt * m[2][2] + wt * m[2][3];
	p->proj.w = xt * m[3][0] + yt * m[3][1] + zt * m[3][2] + wt * m[3][3];
}

void	apply_matrix(t_data *data, double matrix[4][4])
{
	int	l;
	int	c;

	l = 0;
	while (l < data->map.size.y)
	{
		c = 0;
		while (c < data->map.size.x)
		{
			change_cdt(&data->map.point[l][c], matrix);
			c++;
		}
		l++;
	}
}
