/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:19:28 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:44:14 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin_1(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*result;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}
