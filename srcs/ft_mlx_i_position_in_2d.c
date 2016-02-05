/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_position_in_2d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:58:58 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 13:30:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*ft_mlx_i_position_in_2d(void *img, int i, int j)
{
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	img_data = img_data + ((i - 1) * bpp / 8) + j * size_line;
	return (img_data);
}
