/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_mouse_tracking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:14:00 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 10:59:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_mouse_tracking(t_mlx *e)
{
	if (e->mouse_tracking == 0)
		e->mouse_tracking = 1;
	else if (e->mouse_tracking == 1)
	{
		e->mouse_tracking = 0;
		e->m_x_old = e->m_x;
		e->m_y_old = e->m_y;
		e->m_x = (e->win_x_size) / 2;
		e->m_y = (e->win_y_size) / 2;
	}
}
