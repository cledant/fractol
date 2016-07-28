# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_init_cuda.cu                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <cledant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 21:55:33 by cledant           #+#    #+#              #
#    Updated: 2016/07/28 15:27:22 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "fract_ol.h"

static void		ft_init_extent(t_mlx *e)
{
	(e->fl_extent).width = sizeof(float) * e->win_x_size;
	(e->fl_extent).height = sizeof(float) * e->win_y_size;
	(e->fl_extent).depth = sizeof(float) * 5;
	(e->uint_extent).width = sizeof(unsigned int) * e->win_x_size;
	(e->uint_extent).height = sizeof(unsigned int) * e->win_y_size;
	(e->uint_extent).depth = sizeof(unsigned int) * 2;
}

static void		ft_clean(t_mlx *e, int error)
{
	if (error < 2)
		cudaFree(e->fl_matrix);
	if (error < 3)
		cudaFree(e->unit_matrix);
	if (error < 4)
		cudaFree(e->d_x_min);
	if (error < 5)
		cudaFree(e->d_y_max);
	if (error < 6)
		cudaFree(e->d_x_pitch);
	if (error < 7)
		cudaFree(e->d_y_pitch);
}

int				ft_cuda_init(t_mlx *e)
{
	ft_init_extent(e);
	if (cudaMalloc3D(e->fl_matrix, e->fl_extent) != cudaSuccess)
		return (0);
	if (cudaMalloc3D(e->uint_matrix, e->uint_extent) != cudaSuccess)
	{
		ft_clean(1);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_x_min), sizeof(float)) != cudaSuccess)
	{
		ft_clean(2);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_y_max), sizeof(float)) != cudaSuccess)
	{
		ft_clean(3);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_x_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(4);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_y_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(5);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_buff_img), sizeof(int) * e->win_x_size *
					e->win_y_size) != cudaSuccess)
	{
		ft_clean(6);
		return (0);
	}
	return (1);
}
