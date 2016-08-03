/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cuda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:37:10 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 18:54:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		ft_clean(t_mlx *e, int error)
{
	if (error < 2)
		cudaFree(e->d_y_max);
	if (error < 3)
		cudaFree(e->d_x_pitch);
	if (error < 4)
		cudaFree(e->d_y_pitch);
	if (error < 5)
		cudaFree(e->d_buff_img);
	if (error < 6)
		cudaFree(e->d_color);
	if (error < 7)
		cudaFree(e->d_iter);
	if (error < 8)
		cudaFree(e->d_win_x_size);
	if (error < 9)
		cudaFree(e->d_win_y_size);
}

int				ft_cuda_init(t_mlx *e)
{
	size_t	bigger;

	bigger = (e->win_x_size > e->win_y_size) ? e->win_x_size : e->win_y_size;
	e->nb_block = (bigger % M_THREAD == 0) ? bigger / M_THREAD :
		bigger / M_THREAD + 1;
	if (cudaMalloc((void **)(&e->d_x_min), sizeof(float)) != cudaSuccess)
		return (0);
	if (cudaMalloc((void **)(&e->d_y_max), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 1);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_x_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 2);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_y_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 3);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_buff_img), sizeof(int) * e->win_x_size *
					e->win_y_size) != cudaSuccess)
	{
		ft_clean(e, 4);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_color), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 5);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_iter), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 6);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_win_x_size), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 7);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_win_y_size), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 8);
		return (0);
	}
	return (1);
}
