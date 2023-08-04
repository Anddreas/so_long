/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:41:26 by handrias          #+#    #+#             */
/*   Updated: 2023/08/02 17:41:28 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "so_long.h"
#include <mlx.h>

void	width(char **map, t_list *game)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	game->width = i;
}

void	height(char **map, t_list *game)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
		i++;
	game->height = i;
}
