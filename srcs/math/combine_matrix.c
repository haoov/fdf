/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:55:20 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:55:24 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zero_matrix(double m[4][4])
{
	int	l;
	int	c;

	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			m[l][c] = 0;
			c++;
		}
		l++;
	}
}

void	copy_matrix(double tmp[4][4], double m[4][4])
{
	int	l;
	int	c;

	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			m[l][c] = tmp[l][c];
			c++;
		}
		l++;
	}
}

void	combine_matrix(double m[4][4], double m1[4][4], double m2[4][4])
{
	double	tmp[4][4];
	int		l;
	int		c;
	int		i;

	init_zero_matrix(tmp);
	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			i = 0;
			while (i < 4)
			{
				tmp[l][c] += m1[l][i] * m2[i][c];
				i++;
			}
			c++;
		}
		l++;
	}
	copy_matrix(tmp, m);
}
