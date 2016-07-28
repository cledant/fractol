/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_init_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:59:25 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:29:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

float		ft_julia_init_value(int pos, size_t size, int axis)
{
	if (axis == 0)
		return (2 * (pos - ((int)size / 2)) / (float)(size / 2));
	else
		return (2 * (-pos + ((int)size / 2)) / (float)(size / 2));
}
