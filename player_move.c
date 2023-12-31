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

void	go_left2(t_list *game)
{
	if (game->arr[game->x][game->y - 1] == 'E')
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
	game->arr[game->x][game->y - 1] = 'P';
}

void	go_left(t_list *game)
{
	if (game->arr[game->x][game -> y - 1] == 'E')
		check_door(game);
	if (game->arr[game->x][game->y - 1] != '1')
	{
		if (game->arr[game->x][game->y - 1] == 'C')
			game->coins -= 1;
		go_left2(game);
		game->y -= 1;
		game->steps += 1;
		count_steps(game);
	}
}

void	go_right2(t_list *game)
{
	if (game->arr[game->x][game->y + 1] == 'E')
	{
		game->arr[game->x][game->y + 1] = 'P';
		game->arr[game->x][game->y] = '0';
		game->lk = 1;
	}
	else if (game->lk == 1)
	{	
		game->arr[game->x][game->y] = 'E';
		game->arr[game->x][game->y + 1] = 'P';
		game->lk = 0;
	}
	else
	{
		game->arr[game->x][game->y] = '0';
		game->arr[game->x][game->y + 1] = 'P';
	}
}

void	go_right(t_list *game)
{
	if (game->arr[game->x][game -> y + 1] == 'E')
		check_door(game);
	if (game->arr[game->x][game->y + 1] != '1')
	{
		if (game->arr[game->x][game->y + 1] == 'C')
			game->coins -= 1;
		go_right2(game);
		game->y += 1;
		game->steps += 1;
		count_steps(game);
	}
}

int	move_p(int key, t_list *game)
{
	int	i;

	i = 0;
	if (key == 2 || key == 124)
		go_right(game);
	img(game);
	if (key == 0 || key == 123)
		go_left(game);
	img(game);
	if (key == 13 || key == 126)
		go_up(game);
	img(game);
	if (key == 1 || key == 125)
		go_down(game);
	img(game);
	if (key == 53)
		ft_exit(game);
	return (0);
}
