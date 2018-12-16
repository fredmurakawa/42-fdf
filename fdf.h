/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:50:10 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/05/27 18:50:12 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			dist;
	int			px;
	int			py;
	int			inc;
	int			hei;
	int			color;
	int			view;
	int			cols;
	int			lines;
	int			**map_int;
}				t_mlx;

typedef struct	s_seg
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			color;
}				t_seg;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_draw;

void			draw_line(t_seg seg, t_mlx mlx);
void			draw_map(t_mlx mlx);
void			read_file(char *file, int *nbr_lines);
void			set_map(int fd, t_mlx *mlx, int ***map_int);
int				deal_key(int key, t_mlx *mlx);
int				deal_mouse(int x, int y, t_mlx *mlx);
void			set_data(t_mlx *mlx);

#endif
