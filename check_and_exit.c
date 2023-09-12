/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:32:33 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 13:32:34 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_list *game)
{
	(void)game;
	exit(0);
	return (EXIT_SUCCESS);
}

void	check_door(t_list *game)
{
	char	*a;

	if (game->coins == 0)
	{
		game->arr[game->x][game->y] = '0';
		game->steps += 1;
		a = ft_itoa(game->steps);
		write(1, a, ft_strlen(a));
		write(1, "\nThats it)", 9);
		ft_exit(game);
	}
}

void	c_exit(t_list *game)
{
	if (game->coins == 0)
		mlx_put_image_to_window(game->mlx, game ->win, game->open_door_img, \
		game->a * 64, game->b * 64);
	else if (game->coins != 0)
		mlx_put_image_to_window(game->mlx, game ->win, game->close_door_img, \
		game->a * 64, game->b * 64);
}

void	flood_fill(t_list *game, char **map, int x, int y)
{
	// if (map[y][x] == 'E')
	// 	return ;
	if (map[x][y] == '1' || x < 1 || y < 1
		|| y > game->width || x > game->height)
		return ;
	// else if (map[x][y] == 'E')
	// 	return ;
	map[x][y] = '1';
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x, y + 1);
}

int	logic(t_list *game)
{
	int		rows;
	int		colmn;
	char	**arr2;
	int		i;

	i = 0;
	arr2 = NULL;
	rows = matrix_rows(game->arr);
	colmn = matrix_column(game->arr);
	i = logic2(game, arr2, rows);
	return (i);
}
