/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:45:24 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 21:00:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	ft_abs_double_bs(double val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

int				ft_calc_bs(double *init_x, double *init_y, double x, double y)
{
	double	tmp_x;
	double	tmp_y;
	double	sqrt_tmp_x;
	double	sqrt_tmp_y;

	tmp_x = *init_x;
	tmp_y = *init_y;
	tmp_x = ft_abs_double_bs(tmp_x);
	tmp_y = ft_abs_double_bs(tmp_y);
	sqrt_tmp_x = tmp_x * tmp_x;
	sqrt_tmp_y = tmp_y * tmp_y;
	*init_x = (sqrt_tmp_x - sqrt_tmp_y + x);
	*init_y = tmp_x * tmp_y;
	*init_y += *init_y;
	*init_y += y;
	if ((*init_x * *init_x) + (*init_y * *init_y) <= 400000)
		return (0);
	else
		return (1);
}
