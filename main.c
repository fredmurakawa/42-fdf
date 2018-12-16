/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:28:45 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/05/29 21:28:47 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_mlx		mlx;

	if (argc == 2)
	{
		read_file(argv[1], &mlx.lines);
		fd = open(argv[1], O_RDONLY);
		if (!(mlx.map_int = (int **)malloc(sizeof(int *) * mlx.lines)))
			return (1);
		mlx.mlx_ptr = mlx_init();
		set_map(fd, &mlx, &mlx.map_int);
		set_data(&mlx);
		if (2 * mlx.px + mlx.cols * mlx.dist > 2500)
			mlx.dist = 9;
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2 * mlx.px + mlx.cols *
			mlx.dist, 2 * mlx.py + mlx.lines * mlx.dist, "testing mlx");
		draw_map(mlx);
		mlx_key_hook(mlx.win_ptr, deal_key, (void *)&mlx);
		mlx_hook(mlx.win_ptr, 6, 0, deal_mouse, (void *)&mlx);
		mlx_loop(mlx.mlx_ptr);
		free(mlx.map_int);
	}
	return (0);
}
