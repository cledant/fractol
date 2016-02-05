/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_loc_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:57 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 19:30:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <unistd.h>

static void		next_mouse_loc(int x, int y, t_mlx *e)
{
	if (e->m_x != x)
	{
		e->m_x = x;
		if (e->fractal == 2 || e->fractal == 4)
			e->render = 0;
	}
	if (e->m_y != y)
	{
		e->m_y = y;
		if (e->fractal == 2 || e->fractal == 4)
			e->render = 0;
	}
	if ((e->fractal == 2 || e->fractal == 4) && e->render == 0)
	{
		ft_mlx_i_clear_img(e->img, e->win_x_size, e->win_y_size);
		expose_hook(e);
	}
}

int				mouse_loc_hook(int x, int y, t_mlx *e)
{
	if (e->mouse_tracking == 1)
	{
		if (x < 0)
			x = 0;
		else if (x > (int)e->win_x_size)
			x = (int)e->win_x_size;
		if (y < 0)
			y = 0;
		else if (y > (int)e->win_y_size)
			y = (int)e->win_y_size;
		next_mouse_loc(x, y, e);
	}
	return (0);
}
