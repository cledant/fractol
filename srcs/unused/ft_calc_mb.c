/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_mb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:43:44 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 21:00:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_calc_mb(double *init_x, double *init_y, double x, double y)
{
	double	tmp_x;
	double	tmp_y;
	double	sqrt_tmp_x;
	double	sqrt_tmp_y;

	tmp_x = *init_x;
	tmp_y = *init_y;
	sqrt_tmp_x = tmp_x * tmp_x;
	sqrt_tmp_y = tmp_y * tmp_y;
	*init_x = (sqrt_tmp_x - sqrt_tmp_y + x);
	*init_y = tmp_x * tmp_y;
	*init_y += *init_y;
	*init_y += y;
	if ((*init_x * *init_x) + (*init_y * *init_y) <= 4)
		return (0);
	else
		return (1);
}
