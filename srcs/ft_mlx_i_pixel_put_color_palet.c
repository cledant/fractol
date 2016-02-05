/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_pixel_put_color_palet.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:27:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 18:16:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_i_pixel_put_color_palet(t_mlx *e, int i, int j, size_t cur_it)
{
	if (e->color == 1)
		ft_mlx_i_pixel_put(e->img, i, j, 0x000000FF + (cur_it * 0x000FF000));
	else if (e->color == 2)
		ft_mlx_i_pixel_put(e->img, i, j, 0x000F0F0F + (cur_it * 0x00102030));
	else if (e->color == 3)
		ft_mlx_i_pixel_put(e->img, i, j, 0x00F0000F + (cur_it * 0x00111111));
	else if (e->color == 4)
		ft_mlx_i_pixel_put(e->img, i, j, 0x00000000 + (cur_it * 0x00060006));
	else if (e->color == 5)
		ft_mlx_i_pixel_put(e->img, i, j, 0x00A4B580 + (cur_it * 0x00341165));
	else if (e->color == 6)
		ft_mlx_i_pixel_put(e->img, i, j, 0x00000000 + (cur_it * 0x00060100));
}
