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

void	go_up2(t_list *game)
{
	if (game->arr[game->x - 1][game->y] == 'E')
	{
		game->arr[game->x][game->y] = '0';
		game->lk = 1;
	}
	else if (game->lk == 1)
	{	
		game->arr[game->x][game->y] = 'E';
		game->lk = 0;
	}
	else
		game->arr[game->x][game->y] = '0';
	game->arr[game->x - 1][game->y] = 'P';
}

void	go_up(t_list *game)
{
	if (game->arr[game->x - 1][game -> y] == 'E')
		check_door(game);
	if (game->arr[game->x - 1][game->y] != '1')
	{
		if (game->arr[game->x - 1][game->y] == 'C')
			game->coins -= 1;
		go_up2(game);
		game->x -= 1;
		game->steps += 1;
		count_steps(game);
	}
}

void	go_down2(t_list *game)
{
	if (game->arr[game->x + 1][game->y] == 'E')
	{
		game->arr[game->x][game->y] = '0';
		game->lk = 1;
	}
	else if (game->lk == 1)
	{	
		game->arr[game->x][game->y] = 'E';
		game->lk = 0;
	}
	else
		game->arr[game->x][game->y] = '0';
	game->arr[game->x + 1][game->y] = 'P';
}

void	go_down(t_list *game)
{
	if (game->arr[game->x + 1][game -> y] == 'E')
		check_door(game);
	if (game->arr[game->x + 1][game->y] != '1')
	{
		if (game->arr[game->x + 1][game->y] == 'C')
			game->coins -= 1;
		go_down2(game);
		game->x += 1;
		game->steps += 1;
		count_steps(game);
	}
}
