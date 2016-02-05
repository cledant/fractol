/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:35:39 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 10:56:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_i_pixel_put(void *img, int x, int y, int color)
{
	char *ptr_img;

	ptr_img = ft_mlx_i_position_in_2d(img, x, y);
	ft_memmove(ptr_img, &color, sizeof(int));
}
