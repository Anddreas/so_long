/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:28:19 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:26:26 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// char	*ft_strdup2(const char *s1)
// {
// 	char	*str;
// 	int		str_len;

// 	if (!s1)
// 		return (0);
// 	str_len = ft_strlen(s1) + 1;
// 	str = malloc(str_len);
// 	if (str)
// 	{
// 		ft_strlcpy2(str, s1, str_len);
// 		return (str);
// 	}
// 	return (NULL);
// }


char	**ft_strdup_matrix(const char **matrix, int rows, int cols)
{
	char	**duplicate;
	int		i;

	if (!matrix)
		return (NULL);
	duplicate = (char **)malloc((rows + 1) * sizeof(char *));
	if (!duplicate)
		return (NULL);
	for (i = 0; i < rows; i++)
	{
		duplicate[i] = ft_strdup(matrix[i]);
		if (!duplicate[i])
		{
			while (i > 0)
				free(duplicate[--i]);
			free(duplicate);
			return (NULL);
		}
	}
	duplicate[i] = NULL;
	return (duplicate);
}