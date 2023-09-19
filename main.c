/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:06 by handrias          #+#    #+#             */
/*   Updated: 2023/08/02 15:41:26 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_game(t_list *game, char **argv)
{
	if (check_ber(argv) == 1)
		game->fd = open(argv[1], O_RDONLY);
	game->res = process_file(game->fd);
	game->q = ft_strtrim(game->res, "\n");
	game->arr = check(game->q);
	free(game->q);
	check_row(game->arr);
	check_column(game->arr);
	check_utils2(game->arr);
	check_utils(game->arr, game);
	width(game->arr, game);
	height(game->arr, game);
	count_coins(game->arr, game);
	last_check(game);
}

void	img_print(t_list *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
		"images/wall.xpm", &game->i, &game->j);
		game->background = mlx_xpm_file_to_image(game->mlx, \
		"images/bg.xpm", &game->i, &game->j);
		game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"images/player.xpm", &game->i, &game->j);
		game->coin_img = mlx_xpm_file_to_image(game->mlx, \
		"images/coin.xpm", &game->i, &game->j);
		game->open_door_img = mlx_xpm_file_to_image(game->mlx, \
		"images/open_door.xpm", &game->i, &game->j);
		game->close_door_img = mlx_xpm_file_to_image(game->mlx, \
		"images/close_door.xpm", &game->i, &game->j);
}

int	main(int argc, char **argv)
{	
	t_list	game;

	(void)argc;
	game.steps = 0;
	game.lk = 0;
	if (argc == 2)
	{
		setup_game(&game, argv);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.width * 64, \
		game.height * 64, "Hello world!");
		img_print(&game);
		img(&game);
		mlx_hook(game.mlx_win, 2, 1L << 0, move_p, &game);
		mlx_hook(game.mlx_win, 17, 1L << 0, ft_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
