/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:44:00 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:05:30 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*l;
	unsigned char	*k;

	i = 0;
	if (!dst)
		return (0);
	l = (unsigned char *)dst;
	k = (unsigned char *)src;
	if (dst != src && n)
	{
		while (i < n)
		{
			l[i] = k[i];
			i++;
		}
	}	
	return (dst);
}
