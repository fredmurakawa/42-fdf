/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:24:31 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/06/01 16:24:37 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_low(t_seg seg, t_draw draw, t_mlx mlx)
{
	int d;
	int d1;
	int x;
	int y;
	int i;

	d = (draw.dy * 2) - draw.dx;
	d1 = draw.dy * 2;
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, seg.x0, seg.y0, seg.color);
	x = seg.x0 + draw.sx;
	y = seg.y0;
	i = 0;
	while (++i <= draw.dx)
	{
		if (d > 0)
		{
			d += (draw.dy - draw.dx) * 2;
			y += draw.sy;
		}
		else
			d += d1;
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, seg.color);
		x += draw.sx;
	}
}

static void	draw_high(t_seg seg, t_draw draw, t_mlx mlx)
{
	int d;
	int d1;
	int x;
	int y;
	int i;

	d = (draw.dx * 2) - draw.dy;
	d1 = draw.dx * 2;
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, seg.x0, seg.y0, seg.color);
	y = seg.y0 + draw.sy;
	x = seg.x0;
	i = 0;
	while (++i <= draw.dy)
	{
		if (d > 0)
		{
			d += (draw.dx - draw.dy) * 2;
			x += draw.sx;
		}
		else
			d += d1;
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, seg.color);
		y += draw.sy;
	}
}

void		draw_line(t_seg seg, t_mlx mlx)
{
	t_draw	draw;

	draw.dx = abs(seg.x1 - seg.x0);
	draw.dy = abs(seg.y1 - seg.y0);
	draw.sx = (seg.x1 >= seg.x0) ? 1 : -1;
	draw.sy = (seg.y1 >= seg.y0) ? 1 : -1;
	if (draw.dy <= draw.dx)
		draw_low(seg, draw, mlx);
	else
		draw_high(seg, draw, mlx);
}
