# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_init_cuda.cu                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <cledant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 21:55:33 by cledant           #+#    #+#              #
#    Updated: 2016/07/26 22:31:18 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "fract_ol.h"

static void		ft_init_fb_ext(t_mlx *e)
{
	(e->fl_extent).width = sizeof(float) * e->win_x_size;
	(e->fl_extent).height = sizeof(float) * e->win_y_size;
	(e->fl_extent).depth = sizeof(float) * 5;
	(e->uint_extent).width = sizeof(unsigned int) * e->win_x_size;
	(e->uint_extent).height = sizeof(unsigned int) * e->win_y_size;
	(e->uint_extent).depth = sizeof(unsigned int) * 2;
}

int				ft_cuda_init(t_mlx *e)
{
	ft_init_ext(e);
	if (cudaMalloc3D(e->fl_matrix, e->fl_extent) != cudaSuccess)
		return (0);
	if (cudaMalloc3D(e->uint_matrix, e->uint_extent) != cudaSuccess)
	{
		cudaFree(e->fl_matrix);
		return (0);
	}
	cudaMalloc((void **)(&e->d_x_min), sizeof(float));
	return (1);
}
