#include "fract_ol.h"

static void		ft_init_extent(t_mlx *e)
{
	(e->fl_extent).width = sizeof(float) * e->win_x_size;
	(e->fl_extent).height = sizeof(float) * e->win_y_size;
	(e->fl_extent).depth = sizeof(float) * 5;
	(e->uint_extent).width = sizeof(unsigned int) * e->win_x_size;
	(e->uint_extent).height = sizeof(unsigned int) * e->win_y_size;
	(e->uint_extent).depth = sizeof(unsigned int) * 2;
}

static void		ft_clean(t_mlx *e, int error)
{
	if (error < 2)
		cudaFree(e->fl_matrix);
	if (error < 3)
		cudaFree(e->uint_matrix);
	if (error < 4)
		cudaFree(e->d_x_min);
	if (error < 5)
		cudaFree(e->d_y_max);
	if (error < 6)
		cudaFree(e->d_x_pitch);
	if (error < 7)
		cudaFree(e->d_y_pitch);
	if (error < 8)
		cudaFree(e->d_y_pitch);
	if (error < 9)
		cudaFree(e->d_iter);
}

int				ft_cuda_init(t_mlx *e)
{
	e->nb_block = (e->win_x_size % M_THREAD == 0) ? e->win_x_size % M_THREAD :
		e->win_x_size % M_THREAD + 1;
	ft_init_extent(e);
	if (cudaMalloc3D(e->fl_matrix, e->fl_extent) != cudaSuccess)
		return (0);
	if (cudaMalloc3D(e->uint_matrix, e->uint_extent) != cudaSuccess)
	{
		ft_clean(e, 1);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_x_min), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 2);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_y_max), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 3);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_x_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 4);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_y_pitch), sizeof(float)) != cudaSuccess)
	{
		ft_clean(e, 5);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_buff_img), sizeof(int) * e->win_x_size *
					e->win_y_size) != cudaSuccess)
	{
		ft_clean(e, 6);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_color), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 7);
		return (0);
	}
	if (cudaMalloc((void **)(&e->d_iter), sizeof(size_t)) != cudaSuccess)
	{
		ft_clean(e, 8);
		return (0);
	}
	cudaMemcpy(e->d_iter, (const void *)e->iter, sizeof(size_t),
			cudaMemcpyHostToDevice);
	return (1);
}
