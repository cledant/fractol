/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_nchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:55:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/19 10:55:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp_nchar(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	counter;

	counter = 1;
	result = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (*s1 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
