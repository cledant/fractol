/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitch_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:48:53 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:30:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static float	ft_abs_db(float val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

float			ft_pitch_value(float min, float max, size_t size)
{
	float		range;

	range = ft_abs_db(min - max);
	return (range / size);
}
