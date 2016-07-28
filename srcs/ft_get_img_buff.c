/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 20:31:42 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:04:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_get_img_buff(t_mlx *e)
{
	int		bpp;
	int		size_line;
	int		endian;

	e->buff_img = mlx_get_data_addr(e->img, &bpp, &size_line, &endian);
}
