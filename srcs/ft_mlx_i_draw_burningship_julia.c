/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_burningship_julia.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 12:14:02 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:14:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_set_zero_a(size_t *i, size_t *j, size_t *cur_it, size_t *draw)
{
	*i = 0;
	*j = 0;
	*cur_it = 0;
	*draw = 0;
}

static void	ft_set_tracking(t_mlx *e, double *z_r_init, double *z_i_init)
{
	if (e->mouse_tracking == 1)
	{
		*z_r_init = ft_julia_init_value(e->m_x, e->win_x_size, 0);
		*z_i_init = ft_julia_init_value(e->m_y, e->win_y_size, 1);
	}
	else
	{
		*z_r_init = ft_julia_init_value(e->m_x_old, e->win_x_size, 0);
		*z_i_init = ft_julia_init_value(e->m_y_old, e->win_y_size, 1);
	}
}

static void	ft_set_cpy_val(double *cpy_r, double *cpy_i, double z_r_init,
				double z_i_init)
{
	*cpy_r = z_r_init;
	*cpy_i = z_i_init;
}

static void	ft_set_zero_b(size_t *cur_it, size_t *draw, size_t *i)
{
	*cur_it = 0;
	*draw = 0;
	(*i)++;
}

void		ft_mlx_i_draw_burningship_julia(t_mlx *e)
{
	size_t	i;
	size_t	j;
	size_t	cur_it;
	size_t	draw;
	double	cpy_val[4];

	ft_set_zero_a(&i, &j, &cur_it, &draw);
	ft_set_tracking(e, &cpy_val[2], &cpy_val[3]);
	ft_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->x_min + (e->x_pitch * i)),
			(e->y_max - (e->y_pitch * j)));
	while (j < e->win_y_size + 1)
	{
		while (i < e->win_x_size + 1)
		{
			while ((draw = ft_calc_bs(&cpy_val[0], &cpy_val[1], cpy_val[2],
					cpy_val[3]) == 0) && cur_it < e->iter)
				cur_it++;
			if (draw == 0)
				ft_mlx_i_pixel_put_color_palet(e, i, j, cur_it);
			ft_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->x_min +
				(e->x_pitch * i)), (e->y_max - (e->y_pitch * j)));
			ft_set_zero_b(&cur_it, &draw, &i);
		}
		ft_set_zero_b(&draw, &i, &j);
	}
}
