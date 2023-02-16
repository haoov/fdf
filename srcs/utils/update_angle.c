/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:39:13 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 16:27:15 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_angle(t_data *data)
{
	if (data->proj.angle[X] >= 360)
		data->proj.angle[X] -= 360;
	if (data->proj.angle[X] < 0)
		data->proj.angle[X] += 360;
	if (data->proj.angle[Y] >= 360)
		data->proj.angle[Y] -= 360;
	if (data->proj.angle[Y] < 0)
		data->proj.angle[Y] += 360;
	if (data->proj.angle[Z] >= 360)
		data->proj.angle[Z] -= 360;
	if (data->proj.angle[Z] < 0)
		data->proj.angle[Z] += 360;
}
