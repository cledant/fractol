/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_init_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:59:25 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 21:01:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

double		ft_julia_init_value(int pos, size_t size, int axis)
{
	if (axis == 0)
		return (2 * (pos - ((int)size / 2)) / (double)(size / 2));
	else
		return (2 * (-pos + ((int)size / 2)) / (double)(size / 2));
}
