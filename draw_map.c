/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:49:42 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/06/01 16:49:44 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_map(int fd, t_mlx *mlx, int ***map_int)
{
	char	**map_char;
	char	*line;
	int		lines;
	int		i;

	lines = 0;
	while (get_next_line(fd, &line))
	{
		map_char = ft_strsplit(line, ' ');
		(*mlx).cols = 0;
		while (map_char[(*mlx).cols])
			(*mlx).cols++;
		if (!((*map_int)[lines] = (int *)malloc(sizeof(int) * (*mlx).cols)))
			exit(1);
		i = -1;
		while (map_char[++i])
			(*map_int)[lines][i] = ft_atoi(map_char[i]);
		lines++;
		i = -1;
		while (map_char[++i])
			ft_strdel(&map_char[i]);
		free(map_char);
		ft_strdel(&line);
	}
}

static void	draw_ver_lines(t_seg seg, t_mlx mlx)
{
	int		lin;
	int		col;

	col = -1;
	while (++col < mlx.cols)
	{
		lin = -1;
		while (++lin < mlx.lines - 1)
		{
			seg.x0 = mlx.px + col * mlx.dist + mlx.inc * lin - lin * mlx.view +
				mlx.view * 12;
			seg.x1 = mlx.px + col * mlx.dist + mlx.inc * (lin + 1) - (lin + 1) *
				mlx.view + mlx.view * 12;
			seg.y0 = mlx.py + lin * mlx.dist - mlx.map_int[lin][col] * mlx.hei +
				mlx.view * col;
			seg.y1 = mlx.py + (lin + 1) * mlx.dist - mlx.map_int[lin + 1][col] *
				mlx.hei + mlx.view * col;
			if (mlx.map_int[lin][col] > 0 || mlx.map_int[lin + 1][col] > 0)
				seg.color = abs((mlx.map_int[lin][col] +
					mlx.map_int[lin + 1][col]) * mlx.color);
			else
				seg.color = 0x303030;
			draw_line(seg, mlx);
		}
	}
}

static void	draw_hor_lines(t_seg seg, t_mlx mlx)
{
	int		lin;
	int		col;

	lin = -1;
	while (++lin < mlx.lines)
	{
		col = -1;
		while (++col < mlx.cols - 1)
		{
			seg.x0 = mlx.px + col * mlx.dist + mlx.inc * lin - lin * mlx.view +
				mlx.view * 12;
			seg.x1 = mlx.px + (col + 1) * mlx.dist + mlx.inc * lin -
				(lin) * mlx.view + mlx.view * 12;
			seg.y0 = mlx.py + lin * mlx.dist - mlx.map_int[lin][col] * mlx.hei +
				mlx.view * col;
			seg.y1 = mlx.py + lin * mlx.dist -
				mlx.map_int[lin][col + 1] * mlx.hei + mlx.view * (col + 1);
			if (mlx.map_int[lin][col] > 0 || mlx.map_int[lin][col + 1] > 0)
				seg.color = abs((mlx.map_int[lin][col] +
					mlx.map_int[lin][col + 1]) * mlx.color);
			else
				seg.color = 0x303030;
			draw_line(seg, mlx);
		}
	}
}

void		draw_map(t_mlx mlx)
{
	t_seg	seg;

	seg.x0 = 0;
	seg.x1 = 0;
	seg.y0 = 0;
	seg.y1 = 0;
	draw_ver_lines(seg, mlx);
	draw_hor_lines(seg, mlx);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 30, 20, 0xFF0000, "Controls: Q/W \
	Zoom, +/- Color, Up/Down Height, Left/Right Inclination, ]/[ Inclination");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 30, 45, 0xFF0000, "ESC Exit");
}
