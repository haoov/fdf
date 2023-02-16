/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:08 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:09:21 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	leave(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	exit_prg(data, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
