/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_move_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:19:56 by cledant           #+#    #+#             */
/*   Updated: 2016/01/21 20:35:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_move_camera(t_mlx *e, size_t type)
{
	if (type == 0)
	{
		e->y_min = e->y_min + 50 * e->y_pitch;
		e->y_max = e->y_max + 50 * e->y_pitch;
	}
	else if (type == 1)
	{
		e->y_min = e->y_min - 50 * e->y_pitch;
		e->y_max = e->y_max - 50 * e->y_pitch;
	}
	else if (type == 2)
	{
		e->x_min = e->x_min + 50 * e->x_pitch;
		e->x_max = e->x_max + 50 * e->x_pitch;
	}
	else if (type == 3)
	{
		e->x_min = e->x_min - 50 * e->x_pitch;
		e->x_max = e->x_max - 50 * e->x_pitch;
	}
	e->render = 0;
	ft_mlx_i_clear_img(e->img, e->win_x_size, e->win_y_size);
	expose_hook(e);
}
