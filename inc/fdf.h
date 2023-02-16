/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:11:16 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 12:47:53 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_struct.h"
# include "fdf_colors.h"
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <X11/keysym.h>

# define FORMAT_ERR "Error while parsing, check map format"
# define MLX_ERR "Error while using mlx library, check environment"
# define MEM_ERR "Error while allocating memory, check memory usage"
# define DEF_X 1920
# define DEF_Y 1080
# define HEX_BASE "0123456789abcdef"
# define MHEX_BASE "0123456789ABCDEF"
# define HEX_CHAR "0123456789abcdefABCDEF"
# define Z_DIV 10

/*********************STRUCT*********************/

/*See fdf_struct.h*/

/*********************COLORS*********************/

/*See fdf_colors.h*/

/*********************PROTOTYPES*********************/

/*Initialisation and parsing*/
void	init(t_data *data, char *path);
void	init_matrix(t_data *data);
void	init_proj(t_data *data, t_map map);
int		parse_file(char *file_name, t_data *data);
void	parse_corners(t_data *data);
int		check_format(t_data *data, char *str);

/*Colors*/
int		rgb_color(unsigned char r, unsigned char g, unsigned char b);
int		parse_color(char *line);
void	change_theme(t_data *data);
void	apply_theme(t_data *data);
int		get_color(int c1, int c2, int grad, int step);

/*Geometric representations*/
void	isometric(t_data *data);
void	parallel(t_data *data);
void	mvp(t_data *data);

/*Modifications to the map*/
void	translation(t_data *data, int tx, int ty, int tz);
void	scaling(t_data *data, double sx, double sy, double sz);
void	rotation(t_data *data, double t, int axe);
void	projection(t_data *data);
int		zoom_in(void *param, int x, int y);
int		zoom_out(void *param, int x, int y);

/*Drawing inside image and display*/
int		display(t_data *data, t_map map);
void	draw_pixel(t_data *data, int x, int y, int color);
void	draw(t_data *data, t_point *starting_point);
void	draw_line(t_data *data, t_point pa, t_point pb);
void	draw_side(t_data *data);
void	draw_menu(t_data *data);

/*Functions using the mlx lib*/
int		start(t_data *data);
int		key_action(int key_code, void *param);
int		mouse_action(int button, int x, int y, void *param);
int		mouse_motion(int x, int y, void *param);
int		new_image(t_data *data);

/*Math functions*/
void	translation_matrix(t_data *data, int tx, int ty, int tz);
void	scaling_matrix(t_data *data, double sx, double sy, double sz);
void	rotation_matrix(t_data *data, double a, int axe);
void	projection_matrix(t_data *data, double t, double zn, double zf);
void	combine_matrix(double m[4][4], double m1[4][4], double m2[4][4]);
void	apply_matrix(t_data *data, double m[4][4]);
double	max(double a, double b);
double	min(double a, double b);

/*Utils*/
void	reverse_tab(char *bits, int size);
int		get_index(char *str, char *str2, char c);
int		inside_window(t_data *data, t_point p);
void	update_angle(t_data *data);
int		get_next_line_mod(int fd, char **line);

/*Exit the program and free*/
void	free_tab(char **tab);
void	exit_prg(t_data *data, char *msg, int exit_code);
int		leave(void *param);

#endif