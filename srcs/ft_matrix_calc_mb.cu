#include "fract_ol.h"

__device__ static float	ft_mb_it(struct cudaPitchedPtr *ft_matrix, size_t idx_x,
							size_t idx_y, size_t *it_max)
{
	float	it;
	float	sqrt_x;
	float	sqrt_y;
	float	tmp_x;
	float	tmp_y;

	it = 0;
	while (1)
	{
		sqrt_x = ft_matrix[idx_x][idx_y][0] * ft_matrix[idx_x][idx_y][0];
		sqrt_y = ft_matrix[idx_x][idx_y][1] * ft_matrix[idx_x][idx_y][1];
		tmp_x= sqrt_x - sqrt_y + ft_matrix[idx_x][idx_y][2];
		tmp_y = ft_matrix[idx_x][idx_y][0] * ft_matrix[idx_x][idx_y][1];
		tmp_y += tmp_y;
		tmp_y += ft_matrix[idx_x][idx_y][3];
		ft_matrix[idx_x][idx_y][0] = tmp_x; 
		ft_matrix[idx_x][idx_y][1] = tmp_y;
		if ((tmp_x * tmp_x) + (tmp_y * tmp_y) <= 4)
			return (it);
		else
			it++;
		if (it > *it_max)
			return (it);
	}
}

__device__ static unsigned int	ft_calc_color(struct cudaPitchedPtr *uint_matrix,
									size_t	idx_x, size_t idx_y, int *color,
									size_t *it_max)
{
	if (uint_matrix[idx_x][idx_y][0] <= *it_max)
	{
		if (*color == 1)
			return (uint_matrix[idx_x][idx_y][0] * 0x000FF000 + 0x000000FF);
		else if (*color == 2)
			return (uint_matrix[idx_x][idx_y][0] * 0x000F0F0F + 0x00102030);
		else if (*color == 3)
			return (uint_matrix[idx_x][idx_y][0] * 0x00F0000F + 0x00111111);
		else if (*color == 4)
			return (uint_matrix[idx_x][idx_y][0] * 0x00000000 + 0x00060006);
		else if (*color == 5)
			return (uint_matrix[idx_x][idx_y][0] * 0x00A4B580 + 0x00341165);
		else if (*color == 6)
			return (uint_matrix[idx_x][idx_y][0] * 0x00000000 + 0x00060100);
	}
	else
		return (0x00000000);
	return (0x00000000);
}

__global__ void			ft_matrix_calc_mb(struct cudaPitchedPtr *ft_matrix,
							struct cudaPitchedPtr *uint_matrix, float *x_min,
							float *y_max, float *x_pitch, float *y_pitch,
							size_t *win_x_size, size_t *win_y_size, int *color,
							size_t *it_max)
{
	size_t	idx_x;
	size_t	idx_y;

	idx_x = blockIdx.x * blockDim.x + threadIdx.x;
	idx_y = blockIdx.y * blockDim.y + threadIdx.y;
	if (idx_x < *win_x_size && idx_y < *win_y_size)
	{
		ft_matrix[idx_x][idx_y][0] = *x_min + (idx_x * *x_pitch);
		ft_matrix[idx_x][idx_y][1] = *y_max + (idx_y * *y_pitch);
		ft_matrix[idx_x][idx_y][2] = ft_matrix[idx_x][idx_y][0];
		ft_matrix[idx_x][idx_y][3] = ft_matrix[idx_x][idx_y][1];
		ft_matrix[idx_x][idx_y][4] = ft_mb_it(ft_matrix, idx_x, idx_y);
		uint_matrix[idx_x][idx_y][0] = ft_matrix[idx_x][idx_y][4];
		uint_matrix[idx_x][idx_y][1] = ft_calc_color(uint_matrix, idx_x, idx_y,
				color, it_max);
	}
}
