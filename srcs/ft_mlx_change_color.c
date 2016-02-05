/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_change_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:56:27 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 18:02:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_change_color(t_mlx *e)
{
	if (e->color == 6)
		e->color = 1;
	else
		(e->color)++;
	e->render = 0;
	ft_mlx_i_clear_img(e->img, e->win_x_size, e->win_y_size);
	expose_hook(e);
}
