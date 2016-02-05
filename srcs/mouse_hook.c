/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:06 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 19:01:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <unistd.h>

int		mouse_hook(int button, int x, int y, t_mlx *e)
{
	x++;
	y++;
	if (button == MLX_MOUSE_SCROLL_UP)
		ft_mlx_zoom_in(e);
	else if (button == MLX_MOUSE_SCROLL_DOWN)
		ft_mlx_zoom_out(e);
	return (0);
}
