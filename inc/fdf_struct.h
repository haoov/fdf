/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:48 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/07 15:30:41 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "fdf_colors.h"

# define X 0
# define Y 1
# define Z 2

# define UP_LEFT 0
# define UP_RIGHT 1
# define DOWN_LEFT 2
# define DOWN_RIGHT 3

/*Vector 2D*/
typedef struct s_vec2
{
	int	x;
	int	y;
}t_vec2;

/*Vector 3D*/
typedef struct s_cdt
{
	double	x;
	double	y;
	double	z;
	double	w;
}t_cdt;

/*position and projection coordonates and color of each point*/
typedef struct s_point
{
	t_cdt	cdt;
	t_cdt	proj;
	int		height;
	int		color;
}t_point;

/*Modifications zoom moove and rotation*/
typedef struct s_matrix
{
	double	trans[4][4];
	double	scale[4][4];
	double	rot[3][4][4];
	double	mv[4][4];
	double	proj[4][4];
}t_matrix;

/*maps data*/
typedef struct s_map
{
	char	*name;
	t_vec2	size;
	t_vec2	origin;
	t_point	**point;
	t_point	**corner;
	t_color	color;
}t_map;

/*Struct to store the image data*/
typedef struct s_img
{
	void	*id;
	char	*data_addr;
	int		bpp;
	int		size_l;
	int		endian;
}t_img;

/*Struct to store the windows data*/
typedef struct s_win
{
	void	*id;
	t_vec2	size;
	t_vec2	cursor;
}t_win;

/*Struct for the projections data*/
typedef struct s_proj
{
	double	t;
	double	zn;
	double	zf;
	double	zt;
	double	zd;
	double	zr;
	double	angle[3];
}t_proj;

/*Global struct to store mlxs data*/
typedef struct s_data
{
	void		*mlx_id;
	t_win		win;
	t_img		img;
	t_map		map;
	t_proj		proj;
	t_matrix	matrix;
}t_data;

#endif