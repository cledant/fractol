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
void		ft_mlx_i_draw_cuda(t_mlx *e)
{
	dim3 thread2d(M_THREAD_X , M_THREAD_Y);
	dim3 block2d(e->nb_block_x, e->nb_block_y);

	cudaMemcpy(e->d_iter, (const void *)&e->iter, sizeof(size_t),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_win_x_size, (const void *)&e->win_x_size, sizeof(size_t),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_win_y_size, (const void *)&e->win_y_size, sizeof(size_t),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_x_min, (const void *)&e->x_min, sizeof(double),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_y_max, (const void *)&e->y_max, sizeof(double),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_x_pitch, (const void *)&e->x_pitch, sizeof(double),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_y_pitch, (const void *)&e->y_pitch, sizeof(double),
			cudaMemcpyHostToDevice);
	cudaMemcpy(e->d_color, (const void *)&e->color, sizeof(size_t),
			cudaMemcpyHostToDevice);
	if (e->fractal == 1)
	{
		ft_matrix_calc_mb<<<block2d, thread2d>>>(e->d_buff_img,
			e->d_x_min, e->d_y_max, e->d_x_pitch, e->d_y_pitch, e->d_win_x_size,
			e->d_win_y_size, e->d_color, e->d_iter);
	}
	else if (e->fractal == 3)
	{
		ft_matrix_calc_bs<<<block2d, thread2d>>>(e->d_buff_img,
			e->d_x_min, e->d_y_max, e->d_x_pitch, e->d_y_pitch, e->d_win_x_size,
			e->d_win_y_size, e->d_color, e->d_iter);
	}
	cudaMemcpy(e->buff_img, (const void *)e->d_buff_img,
			e->win_x_size * e->win_y_size * sizeof(int), cudaMemcpyDeviceToHost);
}
