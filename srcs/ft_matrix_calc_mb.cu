extern "C"
{
#include "fract_ol.h"
#include <stdio.h>
}

__device__ static size_t		ft_mb_it(double pos_real[2], size_t *it_max)
{
	size_t	it;
	double	sqrt[2];
	double	tmp[2];
	double	init[2];

	it = 0;
	init[0] = 0;
	init[1] = 0;
	while (1)
	{
		sqrt[0] = init[0] * init[0];
		sqrt[1] = init[1] * init[1];
		tmp[0]= sqrt[0] - sqrt[1] + pos_real[0];
		tmp[1] = init[0] * init[1];
		tmp[1] += tmp[1];
		tmp[1] += pos_real[1];
		init[0] = tmp[0]; 
		init[1] = tmp[1];
		if ((init[0] * init[0]) + (init[1] * init[1]) <= 4)
			it++;
		else
			return (it);
		if (it > *it_max)
			return (it);
	}
}

__device__ static unsigned int	ft_calc_color(size_t it, size_t *color, 
									size_t *it_max)
{
	if (it <= *it_max)
	{
		if (*color == 1)
			return (it * 0x000FF000 + 0x000000FF);
		else if (*color == 2)
			return (it * 0x00102030 + 0x000F0F0F);
		else if (*color == 3)
			return (it * 0x00111111 + 0x00F0000F);
		else if (*color == 4)
			return (it * 0x00060006 + 0x00000000);
		else if (*color == 5)
			return (it * 0x00341165 + 0x00A4B580);
		else if (*color == 6)
			return (it * 0x00060100 + 0x00000000);
	}
	else
		return (0x00000000);
	return (0x00000000);
}

__global__ void			ft_matrix_calc_mb(unsigned int *color_buff,
							double *x_min, double *y_max, double *x_pitch,
							double *y_pitch, size_t *win_x_size,
							size_t *win_y_size, size_t *color, size_t *it_max)
{
	size_t	idx_x;
	size_t	idx_y;
	double	pos_real[2];
	size_t	it;

	idx_x = blockIdx.x * blockDim.x + threadIdx.x;
	idx_y = blockIdx.y * blockDim.y + threadIdx.y;
	if (idx_x < *win_x_size && idx_y < *win_y_size)
	{
		pos_real[0] = *x_min + (idx_x * *x_pitch);
		pos_real[1] = *y_max - (idx_y * *y_pitch);
		it = ft_mb_it(pos_real, it_max);
		color_buff[idx_x + idx_y * *win_x_size] = ft_calc_color(it, color,
						it_max);
	}
}
