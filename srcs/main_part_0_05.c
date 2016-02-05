/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part_0_05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 12:06:47 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		main_part_0_05(t_mlx *e, char **argv)
{
	e->disp_iter = ft_strnew(1);
	if (e->disp_iter == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	if (ft_is_str_a_number(argv[2]) == 1 &&
			ft_is_str_a_number(argv[3]) == 1)
	{
		e->win_x_size = ft_atoi(argv[2]);
		e->win_y_size = ft_atoi(argv[3]);
	}
	else
	{
		ft_display_instruction();
		return (0);
	}
	if ((e->win_x_size < 100 || e->win_x_size > 2500) ||
				((e->win_y_size < 100) || (e->win_y_size > 1400)))
	{
		ft_display_instruction();
		return (0);
	}
	ft_mlx_reset(e);
	return (1);
}
