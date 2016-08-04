/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:59:28 by cledant           #+#    #+#             */
/*   Updated: 2016/08/04 01:39:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <unistd.h>

int		expose_hook(t_mlx *e)
{
	if (e->render != 1)
	{
		e->render = 1;
		ft_mlx_i_draw_cuda(e);
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_string_put(e->mlx, e->win, 20, 20, 0x00FFFFFF, e->disp_iter);
	}
	return (0);
}
