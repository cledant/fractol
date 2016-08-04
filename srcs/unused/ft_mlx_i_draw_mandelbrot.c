/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 21:03:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_set_zero_1(size_t *i, size_t *j, size_t *cur_it, size_t *draw)
{
	*i = 0;
	*j = 0;
	*cur_it = 0;
	*draw = 0;
}

static void	ft_set_zero_2(size_t *cur_it, size_t *draw, size_t *i)
{
	*cur_it = 0;
	*draw = 0;
	(*i)++;
}

static void	ft_set_zero_3(size_t *i, size_t *j)
{
	*i = 0;
	(*j)++;
}

void		ft_mlx_i_draw_mandelbrot(t_mlx *e, double z_r_init,
				double z_i_init)
{
	size_t	i;
	size_t	j;
	size_t	cur_it;
	size_t	draw;
	double	cpy_init_val[2];

	ft_set_zero_1(&i, &j, &cur_it, &draw);
	cpy_init_val[0] = z_r_init;
	cpy_init_val[1] = z_i_init;
	while (j < e->win_y_size + 1)
	{
		while (i < e->win_x_size + 1)
		{
			while ((draw = ft_calc_mb(&cpy_init_val[0], &cpy_init_val[1],
					(e->x_min + (e->x_pitch * i)), (e->y_max -
						(e->y_pitch * j))) == 0) && cur_it < e->iter)
				cur_it++;
			if (draw == 0)
				ft_mlx_i_pixel_put_color_palet(e, i, j, cur_it);
			cpy_init_val[0] = z_r_init;
			cpy_init_val[1] = z_i_init;
			ft_set_zero_2(&cur_it, &draw, &i);
		}
		ft_set_zero_3(&i, &j);
	}
}
