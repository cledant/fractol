/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_change_disp_iter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:47:20 by cledant           #+#    #+#             */
/*   Updated: 2016/01/21 20:02:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_mlx_change_disp_iter(t_mlx *e)
{
	char	*tmp;

	tmp = ft_itoa(e->iter);
	if (tmp == NULL)
	{
		ft_putendl("Error");
		ft_mlx_exit(e);
	}
	e->disp_iter = ft_strjoin("Iteration = ", tmp);
	if (e->disp_iter == NULL)
	{
		ft_putendl("Error");
		ft_mlx_exit(e);
	}
	ft_strdel(&tmp);
}
