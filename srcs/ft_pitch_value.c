/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitch_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:48:53 by cledant           #+#    #+#             */
/*   Updated: 2016/01/20 22:47:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static double	ft_abs_db(double val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

double			ft_pitch_value(double min, double max, size_t size)
{
	double		range;

	range = ft_abs_db(min - max);
	return (range / size);
}
