/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 18:48:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" 
{
#include "fract_ol.h"
}

extern "C"
void		ft_mlx_i_draw_mandelbrot_cuda(t_mlx *e)
{
	cudaMemcpy(e->d_x_min, (const void *)&e->x_min, sizeof(float),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_y_max, (const void *)&e->y_max, sizeof(float),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_x_pitch, (const void *)&e->x_pitch, sizeof(float),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_y_pitch, (const void *)&e->y_pitch, sizeof(float),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_color, (const void *)&e->color, sizeof(size_t),
			cudaMemcpyHostToDevice);
	ft_matrix_calc_mb<<<e->nb_block, M_THREAD>>>(e->d_buff_img,
			e->d_x_min, e->d_y_max, e->d_x_pitch, e->d_y_pitch, e->d_win_x_size,
			e->d_win_y_size, e->d_color, e->d_iter);
	cudaMemcpy(e->buff_img, (const void *)e->d_buff_img,
			e->win_x_size * e->win_y_size * sizeof(int), cudaMemcpyDeviceToHost);
}
