/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:26:27 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:38:06 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_key(t_data *data, int key_code)
{
	if (key_code == XK_w)
		data->proj.angle[X] -= 10;
	else if (key_code == XK_s)
		data->proj.angle[X] += 10;
	else if (key_code == XK_d)
		data->proj.angle[Y] -= 10;
	else if (key_code == XK_a)
		data->proj.angle[Y] += 10;
	else if (key_code == XK_t)
		data->proj.angle[Z] += 10;
	else if (key_code == XK_r)
		data->proj.angle[Z] -= 10;
	display(data, data->map);
}

void	movement_key(t_data *data, int key_code)
{
	if (key_code == XK_Right)
		data->map.origin.x += 10;
	else if (key_code == XK_Left)
		data->map.origin.x -= 10;
	else if (key_code == XK_Up)
		data->map.origin.y -= 10;
	else if (key_code == XK_Down)
		data->map.origin.y += 10;
	display(data, data->map);
}

void	scaling_key(t_data *data, int key_code)
{
	if (key_code == XK_minus)
	{
		data->proj.zd++;
		if (data->proj.zd > 1000)
			data->proj.zd = 1000;
	}
	else if (key_code == XK_equal)
	{
		data->proj.zd--;
		if (data->proj.zd < 1)
			data->proj.zd = 1;
	}
	display(data, data->map);
}

void	projection_key(t_data *data, int key_code)
{
	if (key_code == XK_i)
		isometric(data);
	else if (key_code == XK_p)
		parallel(data);
}

int	key_action(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key_code == XK_Escape)
		exit_prg(data, NULL, EXIT_SUCCESS);
	else if (key_code == XK_w || key_code == XK_s
		|| key_code == XK_a || key_code == XK_d
		|| key_code == XK_t || key_code == XK_r)
		rotation_key(data, key_code);
	else if (key_code == XK_Right || key_code == XK_Left
		|| key_code == XK_Up || key_code == XK_Down)
		movement_key(data, key_code);
	else if (key_code == XK_equal || key_code == XK_minus)
		scaling_key(data, key_code);
	else if (key_code == XK_i || key_code == XK_p)
		projection_key(data, key_code);
	return (0);
}
