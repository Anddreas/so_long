/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:07:24 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:33:37 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
