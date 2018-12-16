/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:07:41 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/05/29 22:07:42 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(char *file, int *nbr_lines)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open() failed\n", 14);
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		*nbr_lines = *nbr_lines + 1;
		ft_strdel(&line);
	}
	if (close(fd) == -1)
	{
		write(1, "close() failed\n", 15);
		exit(0);
	}
}

void	key_action(int key, t_mlx *mlx)
{
	if (key == 126)
		(*mlx).hei += 1;
	else if (key == 125)
		(*mlx).hei -= 1;
	else if (key == 124)
		(*mlx).inc += 1;
	else if (key == 123)
		(*mlx).inc -= 1;
	else if (key == 69)
		(*mlx).color += 5000;
	else if (key == 78)
		(*mlx).color -= 5000;
	else if (key == 12)
		(*mlx).dist += 1;
	else if (key == 13)
		(*mlx).dist -= 1;
	else if (key == 30)
		(*mlx).view += 1;
	else if (key == 33)
		(*mlx).view -= 1;
}

int		deal_key(int key, t_mlx *mlx)
{
	int i;

	i = -1;
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		while (++i < (*mlx).lines)
			free((*mlx).map_int[i]);
		free((*mlx).map_int);
		mlx_del((*mlx).mlx_ptr);
		exit(0);
	}
	key_action(key, mlx);
	mlx_clear_window((*mlx).mlx_ptr, (*mlx).win_ptr);
	draw_map((*mlx));
	return (0);
}

int		deal_mouse(int x, int y, t_mlx *mlx)
{
	if (x < 0)
		(*mlx).color = 0xFF0000;
	else if (x >= 0 && x < 300)
		(*mlx).color = 0x00FF00;
	else if (x >= 300 && x < 600)
		(*mlx).color = 0x0000FF;
	else if (x >= 600 && x < 900)
		(*mlx).color = 0x0F5612;
	else if (x >= 900 && x < 1200)
		(*mlx).color = 0x106599;
	else if (x >= 1200 && x < 1500)
		(*mlx).color = 0x002169;
	else if (x >= 1500 && x < 1800)
		(*mlx).color = 0xF03462;
	else if (x >= 1800)
		(*mlx).color = 0x123456;
	(*mlx).hei = -y / 20;
	mlx_clear_window((*mlx).mlx_ptr, (*mlx).win_ptr);
	draw_map((*mlx));
	return (0);
}

void	set_data(t_mlx *mlx)
{
	(*mlx).dist = 35;
	(*mlx).px = 150;
	(*mlx).py = 150;
	(*mlx).inc = 0;
	(*mlx).view = 0;
	(*mlx).hei = 4;
	(*mlx).color = 6000;
}
