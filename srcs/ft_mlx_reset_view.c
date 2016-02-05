/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_reset_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:44:04 by cledant           #+#    #+#             */
/*   Updated: 2016/01/21 12:11:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_reset_view(t_mlx *e)
{
	ft_mlx_reset(e);
	ft_mlx_i_clear_img(e->img, e->win_x_size, e->win_y_size);
	e->render = 0;
	expose_hook(e);
}
