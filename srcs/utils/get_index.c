/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:58:11 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/31 15:58:43 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_index(char *str, char *str2, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str2[i] != '\0')
	{
		if (str[i] == c || str2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}