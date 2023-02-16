/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:19:34 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 13:02:58 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*extract(t_data *data, char **cdt)
{
	t_point		*tab;
	int			c;

	c = 0;
	data->map.size.x = 0;
	while (cdt[data->map.size.x] != NULL)
		data->map.size.x++;
	tab = (t_point *)ft_calloc(data->map.size.x, sizeof (t_point));
	if (tab == NULL)
		(free_tab(cdt), exit_prg(data, MEM_ERR, EXIT_FAILURE));
	while (c < data->map.size.x)
	{
		tab[c].cdt.x = c;
		tab[c].cdt.y = data->map.size.y;
		tab[c].cdt.z = -ft_atoi(cdt[c]);
		tab[c].cdt.w = 1;
		tab[c].height = -tab[c].cdt.z;
		tab[c].color = parse_color(cdt[c]);
		c++;
	}
	return (tab);
}

void	add(t_data *data, char *line)
{
	t_point	**tab;
	char	**cdt;
	int		i;

	i = 0;
	data->map.size.y++;
	tab = (t_point **)ft_calloc(data->map.size.y, sizeof (t_point *));
	if (tab == NULL)
		(free(line), exit_prg(data, MEM_ERR, EXIT_FAILURE));
	cdt = ft_split(line, " \n");
	if (cdt == NULL)
		(free(line), exit_prg(data, MEM_ERR, EXIT_FAILURE));
	tab[data->map.size.y - 1] = extract(data, cdt);
	while (i < data->map.size.y - 1)
	{
		tab[i] = data->map.point[i];
		i++;
	}
	free(data->map.point);
	data->map.point = tab;
	free_tab(cdt);
}

int	parse_file(char *file_name, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_prg(data, strerror(errno), EXIT_FAILURE);
	while (get_next_line_mod(fd, &line) == EXIT_SUCCESS && line != NULL)
	{
		check_format(data, line);
		add(data, line);
		free(line);
	}
	parse_corners(data);
	return (close(fd), EXIT_SUCCESS);
}
