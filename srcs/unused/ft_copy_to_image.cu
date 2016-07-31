#include "fract_ol.h"

__global__ void		ft_copy_to_image(struct cudaPitchedPtr *uint_matrix,
						char *buff, size_t *win_x)
{
	size_t	idx_x;
	size_t	idx_y;

	cpy_buff = buff;
	idx_x = blockIdx.x * blockDim.x + threadIdx.x;
	idx_y = blockIdx.y * blockDim.y + threadIdx.y;
	cpy_buff = cpy_buff + idx_x * 4 + idx_y * win_x;
	cudaMemcpy(buff, uint_matrix[idx_x][idx_y][1], sizeof(int),
			cudaMemcpyDeviceToDevice);
}
