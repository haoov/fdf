/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:21:44 by rsabbah           #+#    #+#             */
/*   Updated: 2023/02/10 13:17:07 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 2 || envp == NULL || *envp == NULL)
		return (EXIT_FAILURE);
	init(&data, argv[1]);
	parse_file(argv[1], &data);
	if (start(&data) == EXIT_FAILURE)
		exit_prg(&data, MLX_ERR, EXIT_FAILURE);
	isometric(&data);
	mlx_hook(data.win.id, 2, 1L << 0, key_action, &data);
	mlx_hook(data.win.id, 4, 1L << 2, mouse_action, &data);
	mlx_hook(data.win.id, 17, 0L, leave, &data);
	mlx_loop(data.mlx_id);
	exit_prg(&data, NULL, EXIT_SUCCESS);
}
