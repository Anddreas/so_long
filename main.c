#include "so_long.h"

int ft_strlen1(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len = 0;
	int j = 0;

	i = 0;
    while(to_find[len])
        len++;
	while(str[j] != '\0')
		j++;
	if(len < j)
	{
		while(i != 4)
		{
			if(str[j - 4] != to_find[i])
			{
				return(0);
			}
			j++;
			i++;
		}
		if(i == 4)
			return(1);
	}
	return(0);
}

int	check_ber(char **argv, t_list *game)
{
	char	**map;

	map = &argv[1];
	if (map == NULL)
		return(0);
	if(ft_strstr(*map,".ber") == 1)
		return(1);
	else
		return(0);
}

char	*process_file(int a, t_list *game)
{
	char	*res = NULL;
	char	*line;
	char	*tmp;

	if (a < 0)
		return(NULL);
	while (1)
	{
		line = get_next_line(a);
		if (line == NULL)
			break;
		if(!res)
			tmp =  ft_strdup(line);
		else
			tmp = ft_strjoin(res, line);
		free(line);
		if(res)
			free(res);
		res = tmp;
	}
	if (res == NULL)
	{
		printf("Error reading file\n");
		exit(1);
	}
	// system("leaks so_long");
	return(res);
}


char	**check(char *q, t_list *game)
{
	int	i;
	size_t	n;
	char	**arr;
	
	i = 0;
	while(q[i] != '\0')
	{
		if (q[i] == '\n' && q[i + 1] == '\n')
		{
			printf("ERROR");
			exit(1);
		}
		i++;
	}
	arr = ft_split(q,'\n');
	i = 0;
	n = ft_strlen1(arr[0]);
	while(arr[i] != NULL)
	{
		if(ft_strlen1(arr[i]) != n)
		{
			printf("Error1");
			exit (1);
		}
		i++;
	}
	return(arr);
}

int	matrix_rows(char **arr)
{
	int row;

	row = 0;
	while(arr[row])
		row++;
	return(row);
}

int	matrix_column(char **arr)
{
	int column;

	column = 0;
	while(arr[0][column])
		column++;
	return(column);
}

void	check_row(char **arr)
{
	int	j;
	int	i;
	int	len;
	
	i = 0;
	j = 0;
	len = matrix_rows(arr);
	while (arr[0][i])
	{
		if(arr[0][i] != '1' || arr[len-1][i] != '1')
		{
			printf("Error2\n");
			exit(1);
		}
		i++;
	}
}

void	check_column(char **arr)
{
	int	j;
	int	i;
	int	len;
	
	i = 0;
	j = 0;
	len = 0;
	len = matrix_column(arr);
	while (arr[i] && arr[i][0])
	{
			if (arr[i][0] != '1' || arr[i][len - 1] != '1')
			{
				printf("Error3\n");
				exit(1);
			}
		i++;
	}
}



void check_utils(char **arr, t_list *game)
{
	int i;
	int j;
	int x;
	int y;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] != '1' && arr[i][j] != '0' && \
			arr[i][j] != 'C' && arr[i][j] != 'P' && arr[i][j] != 'E')
			{
				printf("Error: Invalid symbol detected\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	printf ("%d\n", i);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				printf ("i = %d, j = %d\n", i, j);
				game->x = i;
				game->y = j;
				x = i;
				y = j;
				break;
			}
			j++;

		}
		i++;
	}
	// i = 0;
	// while (arr[i])
	// 	printf("%s\n", arr[i++]);
}



void check_symbols(char **arr, int *hasE, int *hasP, int *hasC);
void check_missing_symbols(int hasE, int hasP, int hasC);

void check_utils2(char **arr)
{
	int hasE = 0;
	int hasP = 0;
	int hasC = 0;

	check_symbols(arr, &hasE, &hasP, &hasC);
	check_missing_symbols(hasE, hasP, hasC);
}

void check_symbols(char **arr, int *hasE, int *hasP, int *hasC)
{
	int i = 0;
	int j = 0;

	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
				*hasE += 1;
			else if (arr[i][j] == 'P')
				*hasP += 1;
			else if (arr[i][j] == 'C')
				*hasC = 1;
			j++;
		}
		i++;
	}
}


void check_missing_symbols(int hasE, int hasP, int hasC)
{
	if (!hasC)
	{
		printf("Error: Missing required symbols\n");
		exit(1);
	}
	if(hasP == 0 || hasE == 0)
	{
		printf("Error: There no Player or exit\n");
		exit(1);
	}
	if(hasE >= 2 || hasP >= 2)
	{
		printf("Error: There are more Players or exits than '1'\n");
		exit(1);
	}
}


void count_coins(char **arr, t_list *game)
{
	int i = 0;
	int j = 0;

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

void img(t_list *game)
{
	game->h = 0;
	while(game->arr[game->h])
	{
		game->k = 0;
		while(game->arr[game->h][game->k])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->background, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin_img, game->k * 64, game->h * 64);
			if (game->arr[game->h][game->k] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->close_door_img, game->k * 64, game->h * 64);
			game->k++;
		}
		game->h++;
	}
}

int	ft_exit(t_list *game)
{
	kill(game->player_img, SIGKILL);
	exit(0);
	return (EXIT_SUCCESS);
}


void check_door(t_list *game)
{
	if(game->coins == 0)
	{
		game->arr[game->x][game->y] = '0';

		write(1,"Thats it)",9);
		ft_exit(game);
	}
}

void go_up(int key, t_list *game)
{
	if (game->arr[game->x - 1][game -> y] == 'E')
		check_door(game);
	else if (game->arr[game->x - 1][game->y] != '1')
	{
		if(game->arr[game->x - 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->x -= 1;
		game->arr[game->x][game->y] = 'P';
	}
}

void go_down(int key, t_list *game)
{
	if (game->arr[game->x + 1][game -> y] == 'E')
		check_door(game);
	else if (game->arr[game->x + 1][game->y] != '1')
	{
		if(game->arr[game->x + 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->x += 1;
		game->arr[game->x][game->y] = 'P';
	}
}


void go_left(int key, t_list *game)
{
	if (game->arr[game->x][game -> y - 1] == 'E')
		check_door(game);
	else if (game->arr[game->x][game->y - 1] != '1')
	{
		if(game->arr[game->x][game->y - 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->y -= 1;
		game->arr[game->x][game->y] = 'P';
	}
}

void go_right(int key, t_list *game)
{
	if(game->arr[game->x][game -> y + 1] == 'E')
		check_door(game);
	else if (game->arr[game->x][game->y + 1] != '1')
	{
		if(game->arr[game->x][game->y + 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		game->y += 1;
		game->arr[game->x][game->y] = 'P';
	}
}

int move_p(int key, t_list *game)
{
	if(key == 2 || key == 124)
	{
		go_right(key, game);
	}
	img(game);
	if(key == 0 || key == 123)
	{
		go_left(key, game);
	}
	img(game);
	if(key == 13 || key == 126)
	{
		go_up(key, game);
	}
	img(game);
	if(key == 1 || key == 125)
	{
		go_down(key, game);
	}
	img(game);
	if(key == 53)
		ft_exit(game);
	return(0);
}

void c_exit(t_list *game)
{
	if(game->coins == 0)
		mlx_put_image_to_window(game->mlx, game ->win, game->open_door_img, game->a * 64, game->b * 64);
	else if(game->coins != 0)
		mlx_put_image_to_window(game->mlx, game ->win, game->close_door_img, game->a * 64, game->b * 64);
}

void	flood_fill(t_list *game, char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'N' || x < 1 || y < 1
		|| y > game->width || x > game->height)
		return ;
	map[x][y] = '1';
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x, y + 1);
}

int logic(t_list *game)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = game->x;
	y = game->y;
	i = 0;
	flood_fill(game, game->arr, x, y);
	while(game->arr[i])
	{
		j = 0;
		while(game->arr[i][j])
		{
			if(game->arr[i][j] == 'E' || game->arr[i][j] == 'C')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

void last_check(t_list *game)
{
	if(logic(game) == 0)
	{
		printf("Error555");
		exit(1);
	}
}

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
	// last_check(&game);
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
