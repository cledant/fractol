extern "C"
{
#include "fract_ol.h"
#include <stdio.h>
}

__device__ unsigned int		ft_calc_color(size_t it, size_t *color, 
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
