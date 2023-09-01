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

char	**ft_strdup_matrix(char **matrix, int rows)
{
	char	**duplicate;
	int		i;

	if (!matrix)
		return (NULL);
	duplicate = (char **)malloc((rows + 1) * sizeof(char *));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		duplicate[i] = ft_strdup(matrix[i]);
		if (!duplicate[i])
		{
			while (i > 0)
				free(duplicate[--i]);
			free(duplicate);
			return (NULL);
		}
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}