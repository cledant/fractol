/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_fractal_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:42:20 by cledant           #+#    #+#             */
/*   Updated: 2016/08/02 18:48:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_fractal_type(t_mlx *e)
{
	if (e->fractal == 1)
		ft_mlx_i_draw_mandelbrot_cuda(e);
	else if (e->fractal == 2)
		ft_mlx_i_draw_julia(e);
	else if (e->fractal == 3)
		ft_mlx_i_draw_burningship(e, 0, 0);
	else if (e->fractal == 4)
		ft_mlx_i_draw_burningship_julia(e);
}
