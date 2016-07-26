/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:30:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/26 23:32:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <string.h>
# include <mlx.h>
# include "libft.h"
# include <cuda.h>
# include <cuda_runtime.h>
# define MLX_KEY_ESC 53
# define MLX_KEY_MINUS 78
# define MLX_KEY_PLUS 69
# define MLX_KEY_R 15
# define MLX_KEY_C 8
# define MLX_KEY_I 34
# define MLX_KEY_U 32
# define MLX_KEY_Z 6
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define MLX_KEY_RIGHT 124
# define MLX_KEY_LEFT 123
# define MLX_MOUSE_SCROLL_UP 5
# define MLX_MOUSE_SCROLL_DOWN 4
# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	int					render;
	void				*img;
	char				*buff_img;
	size_t				iter;
	size_t				win_x_size;
	size_t				win_y_size;
	int					m_x;
	int					m_y;
	int					m_x_old;
	int					m_y_old;
	int					offset_x;
	int					offset_y;
	float				x_min;
	float				x_max;
	float				y_min;
	float				y_max;
	float				x_pitch;
	float				y_pitch;
	float				zoom;
	size_t				color;
	char				*disp_iter;
	int					fractal;
	size_t				mouse_tracking;
	cudaExtent			fl_extent;
	cudaExtent			uint_extent;
	cudaPitchedPtr		*fl_matrix;
	cudaPitchedPtr		*uint_matrix;
	float				*d_x_min;
	float				*d_y_max;
	float				*d_x_pitch;
	float				*d_y_pitch;
	char				*d_buff_img;
}						t_mlx;

char			*ft_mlx_i_position_in_2d(void *img, int i, int j);
void			ft_mlx_i_pixel_put(void *img, int x, int y, int color);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				mouse_loc_hook(int x, int y, t_mlx *e);
int				mouse_hook(int button, int x, int y, t_mlx *e);
void			ft_mlx_i_draw_mandelbrot(t_mlx *e, double z_r_init,
					double z_i_init);
void			ft_mlx_i_draw_burningship(t_mlx *e, double z_r_init,
					double z_i_init);
void			ft_mlx_i_draw_burningship_julia(t_mlx *e);
void			ft_mlx_i_draw_julia(t_mlx *e);
double			ft_julia_init_value(int pos, size_t size, int axis);
void			ft_mlx_i_clear_img(void *img, int i, int j);
void			ft_mlx_i_pixel_put_color_palet(t_mlx *e, int i, int j,
					size_t cur_it);
int				ft_calc_mb(double *init_x, double *init_y, double x, double y);
int				ft_calc_bs(double *init_x, double *init_y, double x, double y);
double			ft_pitch_value(double min, double max, size_t size);
double			ft_offset_value(double value, int offset, double pitch);
int				ft_seek_offset(int size, int pos);
void			ft_mlx_exit(t_mlx *e);
void			ft_mlx_zoom_in(t_mlx *e);
void			ft_mlx_zoom_out(t_mlx *e);
void			ft_mlx_reset(t_mlx *e);
void			ft_mlx_reset_view(t_mlx *e);
void			ft_mlx_change_color(t_mlx *e);
void			ft_mlx_change_iter(t_mlx *e, size_t type);
void			ft_mlx_change_disp_iter(t_mlx *e);
void			ft_mlx_move_camera(t_mlx *e, size_t type);
void			ft_mlx_fractal_type(t_mlx *e);
void			ft_mlx_mouse_tracking(t_mlx *e);
void			ft_display_instruction(void);
int				ft_check_first_argv(char *argv);
int				ft_is_str_a_number(char *str);
int				main_part_0_05(t_mlx *e, char **argv);
int				ft_cuda_init(t_mlx *e);
void			ft_mlx_i_draw_mandelbrot_cuda(t_mlx *e);

#endif
