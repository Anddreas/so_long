#include "so_long.h"

int main(int argc, char **argv)
{
	t_list	game;
	(void)argc;


	if(check_ber(argv, &game) == 1)
		game.fd = open(argv[1], O_RDONLY);
	game.res = process_file(game.fd, &game);
	game.q = ft_strtrim(game.res,"\n");
	game.arr = check(game.q, &game);
	check_row(game.arr);
	check_column(game.arr);
	check_utils2(game.arr);
	check_utils(game.arr, &game);
	width(game.arr, &game);
	height(game.arr, &game);
	count_coins(game.arr,&game);
	last_check(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "Hello world!");
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", &game.i, &game.j);
	game.background = mlx_xpm_file_to_image(game.mlx, "images/bg.xpm", &game.i, &game.j);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "images/player.xpm", &game.i, &game.j);
	game.coin_img = mlx_xpm_file_to_image(game.mlx, "images/coin.xpm", &game.i, &game.j);
	game.open_door_img = mlx_xpm_file_to_image(game.mlx, "images/open_door.xpm", &game.i, &game.j);
	game.close_door_img = mlx_xpm_file_to_image(game.mlx, "images/close_door.xpm", &game.i, &game.j);
	img(&game);

	mlx_hook(game.mlx_win, 2, 1L << 0, move_p, &game);
	mlx_hook(game.mlx_win, 17, 1L << 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return 0;
}
