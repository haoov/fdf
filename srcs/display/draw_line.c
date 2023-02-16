/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:11:15 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 16:18:19 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	conv_2d(t_point *pa, t_point *pb)
{
	pa->proj.x = pa->proj.x / pa->proj.w;
	pa->proj.y = pa->proj.y / pa->proj.w;
	pb->proj.x = pb->proj.x / pb->proj.w;
	pb->proj.y = pb->proj.y / pb->proj.w;
}

void	draw_line(t_data *data, t_point pa, t_point pb)
{
	int		grad;
	int		i;
	t_point	p;

	i = 0;
	conv_2d(&pa, &pb);
	p.cdt.x = pa.proj.x;
	p.cdt.y = pa.proj.y;
	p.color = pa.color;
	grad = (int)max(fabs(pa.proj.x - pb.proj.x), fabs(pa.proj.y - pb.proj.y));
	while (i <= grad)
	{
		p.cdt.x = p.cdt.x + data->map.origin.x;
		p.cdt.y = p.cdt.y + data->map.origin.y;
		if (grad)
			p.color = get_color(pa.color, pb.color, grad, i);
		if (inside_window(data, p))
			draw_pixel(data, p.cdt.x, p.cdt.y, p.color);
		p.cdt.x = pa.proj.x + ((double)i * ((pb.proj.x - pa.proj.x) / grad));
		p.cdt.y = pa.proj.y + ((double)i * ((pb.proj.y - pa.proj.y) / grad));
		i++;
	}
}
