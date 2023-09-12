/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_and_lastcheck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:36:33 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 13:36:35 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_missing_symbols(int hasE, int hasP, int hasC)
{
	(void)hasP;
	(void)hasE;
	if (!hasC)
	{
		printf("Error: Missing required symbols\n");
		exit(1);
	}
	if (hasP == 0 || hasE == 0)
	{
		printf("Error: There no Player or exit\n");
		exit(1);
	}
	if (hasE >= 2 || hasP >= 2)
	{
		printf("Error: There are more Players or exits than '1'\n");
		exit(1);
	}
}

void	count_coins(char **arr, t_list *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'C')
				game->coins += 1;
			j++;
		}
		i++;
	}
}

void	img(t_list *game)
{
	game->h = 0;
	while (game->arr[game->h])
	{
		game->k = 0;
		while (game->arr[game->h][game->k])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->background, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->wall_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->player_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->coin_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->close_door_img, game->k * 64, game->h * 64);
			game->k++;
		}
		game->h++;
	}
}

void	last_check(t_list *game)
{
	if (logic(game) == 0)
	{
		printf("Error556");
		exit(1);
	}
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

int	logic2(t_list *game, char **arr2, int rows)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = game->x;
	y = game->y;
	arr2 = ft_strdup_matrix(game->arr, rows);
	flood_fill(game, arr2, x, y);
	while (arr2[i])
	{
		printf("%s\n",arr2[i]);
		++i;
	}
	i = 0;
	while (arr2 && arr2[i])
	{
		j = 0;
		while (arr2[i][j])
		{
			if (arr2[i][j] == 'E' || arr2[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	free_map(arr2);
	return (1);
}
