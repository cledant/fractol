# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/08/03 21:21:26 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC_CUDA = nvcc

LINKER = g++

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

INCLUDES_LIBMLX = ./minilibx_macos

INCLUDES_CUDA = /Developer/NVIDIA/CUDA-7.5/include

LIBFT_PATH = ./libft

LIBMLX_PATH = ./minilibx_macos

LIB_CUDA = /Developer/NVIDIA/CUDA-7.5/lib

CUDA_ARCH = -arch sm_30

CUDA_OPT = -O2

SRC_NAME =	ft_mlx_i_draw_mandelbrot.c ft_mlx_i_clear_img.c \
			ft_calc_mb.c ft_pitch_value.c ft_offset_value.c ft_seek_offset.c \
			ft_mlx_exit.c ft_mlx_zoom_in.c ft_mlx_zoom_out.c ft_mlx_reset.c \
			ft_mlx_reset_view.c main.c ft_mlx_change_color.c \
			ft_mlx_i_pixel_put_color_palet.c ft_mlx_change_iter.c \
			ft_mlx_change_disp_iter.c ft_mlx_move_camera.c ft_mlx_fractal_type.c \
			ft_mlx_i_draw_julia.c ft_julia_init_value.c ft_mlx_mouse_tracking.c \
			ft_mlx_i_draw_burningship.c ft_calc_bs.c ft_display_instruction.c \
			ft_mlx_i_draw_burningship_julia.c ft_check_first_argv.c expose_hook.c \
			key_hook.c mouse_hook.c mouse_loc_hook.c ft_mlx_i_position_in_2d.c \
			ft_mlx_i_pixel_put.c ft_is_str_a_number.c main_part_0_05.c \
			ft_init_cuda.c ft_get_img_buff.c

SRC_NAME_CUDA = 	ft_mlx_i_draw_mandelbrot_cuda.cu ft_matrix_calc_mb.cu 

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

SRC_CUDA =	$(addprefix $(SRC_PATH),$(SRC_NAME_CUDA))

OBJ =	$(SRC_NAME:.c=.o)

OBJ_CUDA =	$(SRC_NAME_CUDA:.cu=.o)

NAME = fractol

all :	libft libmlx $(NAME)

libft :
	make -C $(LIBFT_PATH)

libmlx :
	make -C $(LIBMLX_PATH)

$(NAME) : $(OBJ) $(OBJ_CUDA)
	$(LINKER) $(OBJ) $(OBJ_CUDA) -o $(NAME) $(CFLAGS) -lft -lmlx -I$(INCLUDES_CUDA) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_LIBMLX) -L$(LIBFT_PATH) -L$(LIBMLX_PATH) -lcudart -L$(LIB_CUDA) -I$(INCLUDES_CUDA) -framework OpenGL -framework Appkit

$(OBJ_CUDA) :
	$(CC_CUDA) -c $(SRC_CUDA) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_LIBMLX) $(CUDA_ARCH) $(CUDA_OPT)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_LIBMLX) -I$(INCLUDES_CUDA)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_CUDA)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBMLX_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean
	rm -rf $(LIBMLX_PATH)/libmlx.a

re : fclean all

.PHONY : all clean fclean re libft libmlx
