/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:14:33 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/31 16:12:19 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_color(char *line)
{
	char	*addr;
	int		color;
	int		i;

	i = 1;
	color = 0;
	addr = ft_strchr(line, ',');
	if (addr == NULL)
		return (WHITE);
	addr = ft_strchr(line, 'x');
	while (addr[i] && ft_strchr(HEX_CHAR, addr[i]) != NULL)
	{
		color = 16 * color + get_index(HEX_BASE, MHEX_BASE, addr[i]);
		i++;
	}
	return (color);
}
