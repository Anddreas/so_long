/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:32 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 11:40:35 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*pr(char *res)
{
	if (res == NULL)
	{
		printf("Error reading file\n");
		exit(1);
	}
	return (res);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
