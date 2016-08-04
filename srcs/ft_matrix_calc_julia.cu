extern "C"
{
#include "fract_ol.h"
}

__device__ static size_t		ft_julia_it(double *pos_real, double init[2],
									size_t *it_max)
{
	size_t	it;
	double	sqrt[2];
	double	tmp[2];

	it = 0;
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

__global__ void			ft_matrix_calc_julia(unsigned int *color_buff,
							double *x_min, double *y_max, double *x_pitch,
							double *y_pitch, size_t *win_x_size,
							size_t *win_y_size, size_t *color, size_t *it_max,
							double *mouse)
{
	size_t	idx_x;
	size_t	idx_y;
	double	pos_real[2];
	double	init[2];
	size_t	it;

	idx_x = blockIdx.x * blockDim.x + threadIdx.x;
	idx_y = blockIdx.y * blockDim.y + threadIdx.y;
	if (idx_x < *win_x_size && idx_y < *win_y_size)
	{
		init[0] = *x_min + (idx_x * *x_pitch);
		init[1] = *y_max - (idx_y * *y_pitch);
		it = ft_julia_it(mouse, init, it_max);
		color_buff[idx_x + idx_y * *win_x_size] = ft_calc_color(it, color,
						it_max);
	}
}
