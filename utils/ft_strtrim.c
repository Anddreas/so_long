/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:31:27 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:48:46 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	first_index(char const *s1, char const *set)
{
	size_t	test;
	size_t	set_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	test = 0;
	set_len = ft_strlen(set);
	while (test < set_len)
	{
		if (s1[i] == set[j])
		{
			test = 0;
			j = 0;
			i++;
		}
		else
		{
			j++;
			test++;
		}
	}
	return (i);
}

size_t	last_index(char const *s1, char const *set)
{
	size_t	test;
	size_t	set_len;
	size_t	s1_len;
	size_t	j;

	j = 0;
	test = 0;
	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1) - 1;
	while (test < set_len)
	{
		if (s1[s1_len] == set[j] && s1_len > 0)
		{
			test = 0;
			j = 0;
			s1_len--;
		}
		else
		{
			j++;
			test++;
		}
	}
	return (s1_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	num;

	if (!s1)
		return (NULL);
	i = first_index(s1, set);
	j = last_index(s1, set);
	if (i > j)
		return (ft_strdup(""));
	num = j - i;
	return (ft_substr(s1, i, num + 1));
}
