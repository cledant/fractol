/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:59:11 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 12:05:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_check_first_argv(char *argv)
{
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(argv, "Julia") == 0)
		return (2);
	else if (ft_strcmp(argv, "BurningShip") == 0)
		return (3);
	else if (ft_strcmp(argv, "BurningShip_Julia") == 0)
		return (4);
	else
		return (0);
}
