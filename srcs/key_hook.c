/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:36 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 10:21:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <unistd.h>

static void		next_key_hook(int keycode, t_mlx *e)
{
	if (keycode == MLX_KEY_RIGHT)
		ft_mlx_move_camera(e, 2);
	else if (keycode == MLX_KEY_LEFT)
		ft_mlx_move_camera(e, 3);
	else if (keycode == MLX_KEY_Z)
		ft_mlx_mouse_tracking(e);
}

int				key_hook(int keycode, t_mlx *e)
{
	if (keycode == MLX_KEY_ESC)
	{
		ft_strdel(&(e->disp_iter));
		ft_mlx_exit(e);
	}
	else if (keycode == MLX_KEY_PLUS)
		ft_mlx_zoom_in(e);
	else if (keycode == MLX_KEY_MINUS)
		ft_mlx_zoom_out(e);
	else if (keycode == MLX_KEY_R)
		ft_mlx_reset_view(e);
	else if (keycode == MLX_KEY_C)
		ft_mlx_change_color(e);
	else if (keycode == MLX_KEY_I)
		ft_mlx_change_iter(e, 1);
	else if (keycode == MLX_KEY_U)
		ft_mlx_change_iter(e, 0);
	else if (keycode == MLX_KEY_UP)
		ft_mlx_move_camera(e, 0);
	else if (keycode == MLX_KEY_DOWN)
		ft_mlx_move_camera(e, 1);
	next_key_hook(keycode, e);
	return (0);
}
