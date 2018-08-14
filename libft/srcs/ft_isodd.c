/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isodd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:05:52 by cledant           #+#    #+#             */
/*   Updated: 2015/11/29 13:56:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isodd(int n)
{
	n = n % 2;
	if (n == 0)
		return (1);
	else if (n == 1 || n == -1)
		return (0);
	return (0);
}