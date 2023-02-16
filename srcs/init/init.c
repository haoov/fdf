/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:14:27 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 19:18:56 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_map_name(char *path)
{
	int		start;
	int		len;
	char	*eop;

	eop = ft_strchr(path, '/');
	if (eop == NULL)
		start = 0;
	else
		start = eop - path + 1;
	len = ft_strlen(path) - start - 4;
	return (ft_substr(path, start, len));
}

void	init(t_data *data, char *path)
{
	ft_memset(data, 0, sizeof(t_data));
	data->map.corner = (t_point **)ft_calloc(4, sizeof (t_point *));
	if (data->map.corner == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	data->map.name = get_map_name(path);
	if (data->map.name == NULL)
		exit_prg(data, MEM_ERR, EXIT_FAILURE);
	data->win.size.x = DEF_X;
	data->win.size.y = DEF_Y;
	data->map.origin.x = data->win.size.x / 2;
	data->map.origin.y = data->win.size.y / 2;
	data->proj.t = 0.1;
	data->proj.zn = 1;
	data->proj.zf = 100;
	data->proj.zd = 10;
	data->map.color.theme = NONE;
	init_matrix(data);
}
