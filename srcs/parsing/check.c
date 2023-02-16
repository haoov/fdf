/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:14:21 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 11:58:06 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*check_base(char *str)
{
	int	i;

	i = 0;
	while (ft_strchr(HEX_CHAR, str[i]) || ft_strchr(", x-", str[i]))
		i++;
	if (str[i] == '\n')
		return (HEX_BASE);
	return (NULL);
}

static int	check_value(char *str, int *c)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		value = 10 * value + str[i] - 48;
		if (value > INT_MAX || (str[0] == '-' && (-value) < INT_MIN))
			return (EXIT_FAILURE);
		i++;
		(*c)++;
	}
	if (ft_strchr(", \n", str[i]) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_color(char *str, int *c)
{
	int		i;
	int		color;

	i = 0;
	if (str[0] == '0' && str[1] == 'x')
	{
		i += 2;
		(*c) += 2;
	}
	while (ft_strchr(HEX_CHAR, str[i]) != NULL)
	{
		color = 16 * color + get_index(HEX_BASE, MHEX_BASE, str[i]);
		if (color > INT_MAX)
			return (EXIT_FAILURE);
		i++;
		(*c)++;
	}
	if (str[i] != ' ' && str[i] != '\n')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_format(t_data *data, char *str)
{
	int			i;

	i = 0;
	if (str[0] == '\n' || check_base(str) == NULL)
		return (EXIT_FAILURE);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (check_value(str + i, &i) == EXIT_FAILURE)
			(free(str), exit_prg(data, FORMAT_ERR, EXIT_FAILURE));
		if (str[i] == ',')
			if (check_color(str + i + 1, &i) == EXIT_FAILURE)
				(free(str), exit_prg(data, FORMAT_ERR, EXIT_FAILURE));
		i++;
	}
	return (EXIT_SUCCESS);
}
