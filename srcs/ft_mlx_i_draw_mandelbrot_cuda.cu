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

#include "fract_ol.h"

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
	cudaMemcpy(e->d_color, (const void *)e->color, sizeof(size_t),
			cudaMemcpyHostToDevice);
	ft_matrix_calc_mb<<<e->nb_block, M_THREAD>>>(e->fl_matrix, e->uint_matrix,
			e->d_x_min, e->d_y_max, e->d_x_pitch, e->d_y_pitch, e->d_win_x_size,
			e->d_win_y_size, e->d_color, e->d_iter);
	ft_copy_to_image<<<e->nb_block, M_THREAD>>>(e->uint_matrix, e->d_buff_img,
			e->d_win_x_size);
	cudaMemcpy(e->buff_img, (const void *)e->d_buff_img,
			e->win_x_size * e->win_y_size * 4, cudaMemcpyDeviceToHost);
}
