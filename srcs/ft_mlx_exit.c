/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:10:58 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 18:05:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_exit(t_mlx *e)
{
	cudaFree(e->fl_matrix);
	cudaFree(e->uint_matrix);
	cudaFree(e->d_x_min);
	cudaFree(e->d_y_max);
	cudaFree(e->d_x_pitch);
	cudaFree(e->d_y_pitch);
	cudaFree(e->d_buff_img);
	cudaFree(e->d_color);
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}
