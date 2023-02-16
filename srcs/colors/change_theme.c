/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:24:57 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 11:25:15 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_earth(t_data *data)
{
	data->map.color.bottom = DEEP_BLUE;
	data->map.color.under = RAINBOW_INDIGO;
	data->map.color.ground = MIDDLE_GREEN;
	data->map.color.upper = RIFLE_BROWN;
	data->map.color.top = ALMOND;
}

void	change_mars(t_data *data)
{
	data->map.color.bottom = EARTH_BROWN;
	data->map.color.under = DARK_CHESTNUT;
	data->map.color.ground = DEER;
	data->map.color.upper = CINEREOUS;
	data->map.color.top = TERRA_COTTA;
}

void	change_space(t_data *data)
{
	data->map.color.bottom = BLACK;
	data->map.color.under = RAISIN_BLACK;
	data->map.color.ground = OUTER_SPACE;
	data->map.color.upper = DEEP_SPACE;
	data->map.color.top = WHITE;
}

void	change_theme(t_data *data)
{
	if (data->map.color.theme == EARTH)
		change_earth(data);
	else if (data->map.color.theme == MARS)
		change_mars(data);
	else if (data->map.color.theme == SPACE)
		change_space(data);
}
