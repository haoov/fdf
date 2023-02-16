/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:47:25 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:47:26 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 						(1 0 0 TX)
translation matrix Mt =	(0 1 0 TY)
						(0 0 1 TZ)
						(0 0 0 1 ) */

void	translation_matrix(t_data *data, int tx, int ty, int tz)
{
	data->matrix.trans[0][3] = tx;
	data->matrix.trans[1][3] = ty;
	data->matrix.trans[2][3] = tz;
}
