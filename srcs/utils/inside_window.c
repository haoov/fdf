/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:48:06 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 18:48:07 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	inside_window(t_data *data, t_point p)
{
	if (p.cdt.x < 0 || p.cdt.x > data->win.size.x)
		return (0);
	if (p.cdt.y < 0 || p.cdt.y > data->win.size.y)
		return (0);
	return (1);
}
