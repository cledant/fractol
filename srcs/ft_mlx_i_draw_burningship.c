/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_burningship.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:08:30 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 21:02:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		ft_init_val(size_t *i, size_t *j, size_t *cur_it, size_t *draw)
{
	*i = 0;
	*j = 0;
	*cur_it = 0;
	*draw = 0;
}

static void		ft_reset_val(size_t *cur_it, size_t *draw, size_t *i)
{
	*cur_it = 0;
	*draw = 0;
	(*i)++;
}

static void		ft_set_cpy_val(double *cpy_r, double *cpy_i, double z_r_init,
					double z_i_init)
{
	*cpy_r = z_r_init;
	*cpy_i = z_i_init;
}

void			ft_mlx_i_draw_burningship(t_mlx *e, double z_r_init,
					double z_i_init)
{
	size_t	i;
	size_t	j;
	size_t	cur_it;
	size_t	draw;
	double	cpy_init_val[2];

	ft_init_val(&i, &j, &cur_it, &draw);
	ft_set_cpy_val(&cpy_init_val[0], &cpy_init_val[1], z_r_init, z_i_init);
	while (j < e->win_y_size + 1)
	{
		while (i < e->win_x_size + 1)
		{
			while ((draw = ft_calc_bs(&cpy_init_val[0], &cpy_init_val[1],
					(e->x_min + (e->x_pitch * i)), -(e->y_max -
						(e->y_pitch * j))) == 0) && cur_it < e->iter)
				cur_it++;
			if (draw == 0)
				ft_mlx_i_pixel_put_color_palet(e, i, j, cur_it);
			cpy_init_val[0] = z_r_init;
			cpy_init_val[1] = z_i_init;
			ft_reset_val(&cur_it, &draw, &i);
		}
		i = 0;
		j++;
	}
}
