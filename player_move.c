/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:30:27 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 13:30:28 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(int key, t_list *game)
{
	if (game->arr[game->x - 1][game -> y] == 'E')
		check_door(game);
	else if (game->arr[game->x - 1][game->y] != '1')
	{
		if (game->arr[game->x - 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->x -= 1;
		game->arr[game->x][game->y] = 'P';
		game->steps += 1;
		count_steps(game);
	}
}

void	go_down(int key, t_list *game)
{
	if (game->arr[game->x + 1][game -> y] == 'E')
		check_door(game);
	else if (game->arr[game->x + 1][game->y] != '1')
	{
		if (game->arr[game->x + 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->x += 1;
		game->arr[game->x][game->y] = 'P';
		game->steps += 1;
		count_steps(game);
	}
}

void	go_left(int key, t_list *game)
{
	if (game->arr[game->x][game -> y - 1] == 'E')
		check_door(game);
	else if (game->arr[game->x][game->y - 1] != '1')
	{
		if (game->arr[game->x][game->y - 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->y -= 1;
		game->arr[game->x][game->y] = 'P';
		game->steps += 1;
		count_steps(game);
	}
}

void	go_right(int key, t_list *game)
{
	if (game->arr[game->x][game -> y + 1] == 'E')
		check_door(game);
	else if (game->arr[game->x][game->y + 1] != '1')
	{
		if (game->arr[game->x][game->y + 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->y += 1;
		game->arr[game->x][game->y] = 'P';
		game->steps += 1;
		count_steps(game);
	}
}

int	move_p(int key, t_list *game)
{
	if (key == 2 || key == 124)
	{
		go_right(key, game);
	}
	img(game);
	if (key == 0 || key == 123)
	{
		go_left(key, game);
	}
	img(game);
	if (key == 13 || key == 126)
	{
		go_up(key, game);
	}
	img(game);
	if (key == 1 || key == 125)
	{
		go_down(key, game);
	}
	img(game);
	if (key == 53)
		ft_exit(game);
	return (0);
}
