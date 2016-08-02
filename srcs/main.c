/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/03 01:21:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int		main_part_1(t_mlx *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	if (ft_cuda_init(e) == 0)
	{
		ft_putendl("Error");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, e->win_x_size, e->win_y_size, "Fract'ol");
	if (e->win == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->img = mlx_new_image(e->mlx, e->win_x_size, e->win_y_size);
	if (e->img == NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("Error");
		return (0);
	}
	ft_get_img_buff(e);
	e->render = 0;
	return (1);
}

static int		main_part_0(t_mlx *e, char **argv)
{
	if ((e->fractal = ft_check_first_argv(argv[1])) == 0)
	{
		ft_display_instruction();
		return (0);
	}
	else
	{
		e->disp_iter = ft_strnew(1);
		if (e->disp_iter == NULL)
		{
			ft_putendl("Error");
			return (0);
		}
		e->win_x_size = 500;
		e->win_y_size = 500;
		ft_mlx_reset(e);
	}
	return (1);
}

static int		main_part_0_5(t_mlx *e, char **argv)
{
	if ((e->fractal = ft_check_first_argv(argv[1])) == 0)
	{
		ft_display_instruction();
		return (0);
	}
	else
	{
		if (main_part_0_05(e, argv) == 0)
			return (0);
	}
	return (1);
}

static int		main_part_minus_1(t_mlx *e, int argc, char **argv)
{
	if (argc == 1)
	{
		ft_display_instruction();
		return (0);
	}
	else if (argc == 2)
	{
		if (main_part_0(e, argv) == 0)
			return (0);
	}
	else if (argc == 4)
	{
		if (main_part_0_5(e, argv) == 0)
			return (0);
	}
	else
	{
		ft_display_instruction();
		return (0);
	}
	if (main_part_1(e) == 0)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_mlx		e;

	if (main_part_minus_1(&e, argc, argv) == 0)
		return (0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_loc_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
