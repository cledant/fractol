/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_zoom_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:14:58 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 20:31:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		ft_mlx_zoom_in_val(t_mlx *e)
{
	e->offset_x = ft_seek_offset(e->win_x_size, e->m_x);
	e->offset_y = ft_seek_offset(e->win_y_size, e->m_y);
	e->x_min = ft_offset_value(e->x_min, e->offset_x, e->x_pitch);
	e->x_max = ft_offset_value(e->x_max, e->offset_x, e->x_pitch);
	e->y_min = ft_offset_value(e->y_min, -e->offset_y, e->y_pitch);
	e->y_max = ft_offset_value(e->y_max, -e->offset_y, e->y_pitch);
	e->x_min = e->x_min + (4 / (e->zoom + e->zoom));
	e->x_max = e->x_max - (4 / (e->zoom + e->zoom));
	e->y_min = e->y_min + (4 / (e->zoom + e->zoom));
	e->y_max = e->y_max - (4 / (e->zoom + e->zoom));
	e->x_pitch = ft_pitch_value(e->x_min, e->x_max, e->win_x_size);
	e->y_pitch = ft_pitch_value(e->y_min, e->y_max, e->win_y_size);
	e->x_min = e->x_min - (e->offset_x * e->x_pitch);
	e->x_max = e->x_max - (e->offset_x * e->x_pitch);
	e->y_min = e->y_min - (-e->offset_y * e->y_pitch);
	e->y_max = e->y_max - (-e->offset_y * e->y_pitch);
}

void			ft_mlx_zoom_in(t_mlx *e)
{
	if (e->zoom < 1e300)
	{
		e->zoom += e->zoom;
		ft_mlx_zoom_in_val(e);
		e->render = 0;
		ft_mlx_i_clear_img(e->img, e->win_x_size, e->win_y_size);
		expose_hook(e);
	}
}
