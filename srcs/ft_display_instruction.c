/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:19:04 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 11:17:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		ft_display_next_int(void)
{
	ft_putendl("");
	ft_putendl("--MOUSE COMMANDS");
	ft_putendl("");
	ft_putendl("SCROLL UP = ZOOM IN");
	ft_putendl("SCROLL DOWN = ZOOM OUT");
	ft_putendl("");
	ft_putendl("--KEY COMMANDS");
	ft_putendl("");
	ft_putendl("PLUS = ZOOM IN");
	ft_putendl("MINUS = ZOOM OUT");
	ft_putendl("R = RESET TO INITIAL CONFIGURATION");
	ft_putendl("I = INCREASE THE NUMBER OF ITERATION BY 10");
	ft_putendl("U = DECREASE THE NUMBER OF ITERATION BY 10");
	ft_putendl("C = CHANGE COLOR PALET");
	ft_putendl("ARROWS = MOVE ON SCREEN");
	ft_putendl("Z = DISABLE MOUSE POSITION TRACKING");
	ft_putstr("	Note : When activated zoom is done at the");
	ft_putendl(" screen's center");
}

void			ft_display_instruction(void)
{
	ft_putendl("	--Man Fractol--");
	ft_putendl("");
	ft_putendl("--ARGUMENTS");
	ft_putendl("");
	ft_putendl("The first Argument is the fractal's name");
	ft_putendl("	The following list is available :");
	ft_putendl("		Mandelbrot");
	ft_putendl("		Julia");
	ft_putendl("		BurningShip");
	ft_putendl("		BurningShip_Julia");
	ft_putendl("");
	ft_putendl("The second Argument is the window lenght");
	ft_putendl("The third Argument is the window height");
	ft_putendl("	Minimum size for both is : 100");
	ft_putendl("	Maximum size for lenght is : 2500");
	ft_putendl("	Maximum size for height is : 1400");
	ft_putendl("");
	ft_putstr("	Note : The minimum argument required to run");
	ft_putendl(" this program is the first one");
	ft_putstr("	Note2 : The second and third arguments must");
	ft_putendl(" be used together");
	ft_putendl("	Note3 : The arguments must be used in the same order");
	ft_putendl("	Note4 : Base window size is 500 x 500");
	ft_display_next_int();
}
