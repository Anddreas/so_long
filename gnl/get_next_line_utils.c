/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:40:44 by handrias          #+#    #+#             */
/*   Updated: 2023/02/17 15:40:56 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*k;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	k = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!k)
		return (NULL);
	while (s1 && s1[i])
	{
		k[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		k[i++] = s2[j++];
	}
	k[i] = '\0';
	return (k);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*k;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	k = malloc(len + 1);
	if (!k)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
	{
		k[j] = s[i];
		j++;
		i++;
	}
	k[j] = '\0';
	return (k);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*dest;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + 1;
	dest = (char *)malloc(l);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, l);
	return (dest);
}
