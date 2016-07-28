/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_mb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:43:44 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:28:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_calc_mb(float *init_x, float *init_y, float x, float y)
{
	float	tmp_x;
	float	tmp_y;
	float	sqrt_tmp_x;
	float	sqrt_tmp_y;

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
