/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:53:54 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:53:55 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_next_line_mod(int fd, char **line)
{
	char	buf[1];

	*line = get_next_line(fd);
	if (line == NULL)
		if (read(fd, buf, 1) != 0)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
