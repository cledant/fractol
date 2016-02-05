/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:37:39 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 18:11:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_mlx_internal_first(t_mlx *e)
{
	e->zoom = 1;
	e->m_x = e->win_x_size / 2;
	e->m_y = e->win_y_size / 2;
	e->m_x_old = e->win_x_size / 2;
	e->m_y_old = e->win_y_size / 2;
	e->x_min = -2;
	e->x_max = 2;
	e->y_min = -2;
	e->y_max = 2;
	e->color = 1;
	e->iter = 100;
}

void		ft_mlx_reset(t_mlx *e)
{
	char	*tmp;

	ft_mlx_internal_first(e);
	ft_strdel(&(e->disp_iter));
	if ((tmp = ft_itoa(e->iter)) == NULL)
	{
		ft_putendl("Error");
		ft_mlx_exit(e);
	}
	if ((e->disp_iter = ft_strjoin("Iteration = ", tmp)) == NULL)
	{
		ft_putendl("Error");
		ft_mlx_exit(e);
	}
	ft_strdel(&tmp);
	e->x_pitch = ft_pitch_value(e->x_min, e->x_max, e->win_x_size);
	e->y_pitch = ft_pitch_value(e->y_min, e->y_max, e->win_y_size);
	e->mouse_tracking = 1;
}
