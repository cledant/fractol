/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_clear_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:28:05 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 18:49:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

void	ft_mlx_i_clear_img(void *img, int i, int j)
{
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	ft_bzero(img_data, (i * bpp / 8) + j * size_line);
}
