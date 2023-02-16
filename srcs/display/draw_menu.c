/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:55:39 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:55:40 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_title(t_data *data)
{
	char	*title;

	title = ft_strjoin("Map name : ", data->map.name);
	if (title == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	mlx_string_put(data->mlx_id, data->win.id, 125 - (3 * ft_strlen(title)),
		25, WHITE, title);
	free(title);
}

void	draw_map_size(t_data *data)
{
	char	*x;
	char	*y;
	char	*size;
	char	*tmp;

	x = ft_itoa(data->map.size.x);
	if (x == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	y = ft_itoa(data->map.size.y);
	if (y == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	tmp = ft_strjoin(x, "x");
	if (tmp == NULL)
		(free(x), free(y), exit_prg(data, MEM_ERR, EXIT_FAILURE));
	size = ft_strjoin(tmp, y);
	if (size == NULL)
		(free(x), free(y), free(tmp), exit_prg(data, MEM_ERR, EXIT_FAILURE));
	mlx_string_put(data->mlx_id, data->win.id, 105, 95, WHITE, size);
	(free(x), free(y), free(tmp), free(size));
}

void	draw_zdiv(t_data *data)
{
	char	*zdiv;
	int		len;

	zdiv = ft_itoa((int)data->proj.zd);
	if (zdiv == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	len = ft_strlen(zdiv);
	mlx_string_put(data->mlx_id, data->win.id, 135, 115, RED, "[-]");
	mlx_string_put(data->mlx_id, data->win.id, 165 - len * 3, 115, WHITE, zdiv);
	mlx_string_put(data->mlx_id, data->win.id, 178, 115, RED, "[+]");
	free(zdiv);
}

void	draw_colors(t_data *data)
{
	mlx_string_put(data->mlx_id, data->win.id, 25, 295, WHITE, "Colors :");
	if (data->map.color.theme == EARTH)
		mlx_string_put(data->mlx_id, data->win.id, 50, 315, RED, "[EARTH]");
	else
		mlx_string_put(data->mlx_id, data->win.id, 50, 315, WHITE, "[EARTH]");
	if (data->map.color.theme == SPACE)
		mlx_string_put(data->mlx_id, data->win.id, 50, 335, RED, "[SPACE]");
	else
		mlx_string_put(data->mlx_id, data->win.id, 50, 335, WHITE, "[SPACE]");
	if (data->map.color.theme == MARS)
		mlx_string_put(data->mlx_id, data->win.id, 50, 355, RED, "[MARS]");
	else
		mlx_string_put(data->mlx_id, data->win.id, 50, 355, WHITE, "[MARS]");
}

void	draw_menu(t_data *data)
{
	draw_title(data);
	mlx_string_put(data->mlx_id, data->win.id, 25, 75, WHITE, "Map infos");
	mlx_string_put(data->mlx_id, data->win.id, 50, 95, WHITE, "- Size :");
	draw_map_size(data);
	mlx_string_put(data->mlx_id, data->win.id, 50, 115, WHITE, "- z divisor :");
	draw_zdiv(data);
	mlx_string_put(data->mlx_id, data->win.id, 25, 155, WHITE, "Controls");
	mlx_string_put(data->mlx_id, data->win.id, 50, 175, WHITE,
		"X Rotate : W-S");
	mlx_string_put(data->mlx_id, data->win.id, 50, 195, WHITE,
		"Y Rotate : A-D");
	mlx_string_put(data->mlx_id, data->win.id, 50, 215, WHITE,
		"Z Rotate : R-T");
	mlx_string_put(data->mlx_id, data->win.id, 50, 235, WHITE, "Moove : arrow");
	mlx_string_put(data->mlx_id, data->win.id, 50, 255, WHITE, "Zoom : roll");
	draw_colors(data);
}
