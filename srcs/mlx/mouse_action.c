/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:26:37 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:53:37 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MINUS 0
#define PLUS 1

void	scaling_button(t_data *data, int sign)
{
	if (sign == PLUS)
	{
		data->proj.zd++;
		if (data->proj.zd > 1000)
			data->proj.zd = 1000;
	}
	else if (sign == MINUS)
	{
		data->proj.zd--;
		if (data->proj.zd < 1)
			data->proj.zd = 1;
	}
	display(data, data->map);
}

void	color_button(t_data *data, int theme)
{
	data->map.color.theme = theme;
	change_theme(data);
	apply_theme(data);
	display(data, data->map);
}

void	click(t_data *data, int x, int y)
{
	if (x >= 135 && x <= 145 && y >= 105 && y <= 120)
		scaling_button(data, MINUS);
	else if (x >= 178 && x <= 198 && y >= 105 && y <= 120)
		scaling_button(data, PLUS);
	else if (x >= 50 && x <= 100 && y >= 305 && y <= 320)
		color_button(data, EARTH);
	else if (x >= 50 && x <= 95 && y >= 325 && y <= 340)
		color_button(data, SPACE);
	else if (x >= 50 && x <= 85 && y >= 340 && y <= 360)
		color_button(data, MARS);
}

int	mouse_action(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		click(data, x, y);
	if (button == 4)
		zoom_in(data, x, y);
	if (button == 5)
		zoom_out(data, x, y);
	return (EXIT_SUCCESS);
}
