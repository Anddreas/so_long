#include "so_long.h"

int ft_strlen1(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

// char	*ft_strjoin_3(char *s1, char *s2)
// {
// 	char	*k;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	k = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
// 	if (!k)
// 		return (NULL);
// 	while (s1 != NULL && s1[i])
// 	{
// 		k[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 != NULL && s2[j])
// 	{
// 		k[i++] = s2[j++];
// 	}
// 	if (s1)
// 		free(s1);
// 	k[i] = '\0';
// 	return (k);
// }

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

int	check_ber(char **argv)
{
	char	**map;
	t_list *game;

	map = &argv[1];
	if (map == NULL)
		return(0);
	if(ft_strstr(*map,".ber") == 1)
		return(1);
	else
		return(0);
}

char	*process_file(int a)
{
	char	*res = NULL;
	char	*line;
	char	*tmp;
	t_list	*game;

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


char	**check(char *q)
{
	int	i;
	size_t	n;
	t_list *game;
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

void check_utils(char **arr)
{
	int i;
	int j;
	
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
				*hasE = 1;
			else if (arr[i][j] == 'P')
				*hasP = 1;
			else if (arr[i][j] == 'C')
				*hasC = 1;
			j++;
		}
		i++;
	}
}

void check_missing_symbols(int hasE, int hasP, int hasC)
{
	if (!hasE || !hasP || !hasC)
	{
		printf("Error: Missing required symbols\n");
		exit(1);
	}
}

void img(t_list *game, int x, int y)
{
	while(game->arr[game->h])
	{
		game->k = 0;
		while(game->arr[game->h][game->k])
		{
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
	// mlx_put_image_to_window(game->mlx, game ->win, game->background, x * 64, y * 64);
	// if(game->arr[x][y] == '1')
	// 	mlx_put_image_to_window(game->mlx, game ->win, game->wall_img, x * 64, y * 64);
	// if(game->arr[x][y] == 'E')
	// 	c_exit(game);
	// if(game->arr[x][y] == 'C')
	// 	mlx_put_image_to_window(game->mlx, game ->win, game->coin_img, x * 64, y * 64);
	// if(game->arr[x][y] == 'P')
	// 	mlx_put_image_to_window(game->mlx, game ->win, game->player_img, x * 64, y * 64);
}

//stexic
void movement(t_list *game, int key)
{     
	if (key == 13 || key == 126)
		game->x -= 1;
	if(key == 2 || key == 124)
		game->y += 1;
	if (key == 1 || key == 125)
		game->x += 1;
	if (key == 0 || key == 123)
		game->y -= 1;
}

void graphic(t_list *game)
{
	int x;
	int y;
	
	mlx_clear_window (game->mlx, game->win);
	x = 0;
	while (game->arr[x])
	{
		y = 0;
		while (game->arr[x][y])
		{
			if (game->arr[x][y] == 'P')
			{
				game->x = x;
				game->y = y;
			}
			if (game->arr[x][y] == 'E')
			{
				game->a = x;
				game->b = y;
			}
			img(game, x, y);
			y++;
		}
		x++;
	}
}

int steps(t_list *game)
{
	char *s;

	s = ft_itoa(game->steps);
	graphic(game);
	mlx_string_put(game->mlx, game->win, 14,7,0x003300FF,s);
	free(s);
	return(0);
}

void check_door(t_list *game, int key)
{
	if(game -> coins == 0)
	{
		game->arr[game->x][game->y] = '0';
		img(game, game->x, game->y);
		movement(game, key);
		img(game, game->x, game->y);
		game->steps += 1;
		steps(game);
	}
	else if(game->coins == 0)
	{
		game->arr[game->x][game->y] = '0';
		movement(game, key);
		game->arr[game->x][game->y] = 'P';
		img(game, game->x, game->y);
		game->steps += 1;
		steps(game);
		write(1,"Congratulations!\n",18);
	}
}

//stex

void go_up(int key, t_list *game)
{
	if (game->arr[game->x - 1][game->y] != '1'
		&& game->arr[game->x - 1][game->y] != 'E')
	{
		if(game->arr[game->x - 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		img(game, game->x, game->y);

		game->x -= 1;
		game->arr[game->x - 1][game->y] = 'P';
	}
	else if(game->arr[game->x - 1][game -> y] == 'E')
		check_door(game, key);
}
void go_down(int key, t_list *game)
{
	if (game->arr[game->x + 1][game->y] != '1'
		&& game->arr[game->x + 1][game->y] != 'E')
	{
		if(game->arr[game->x + 1][game->y] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		img(game, game->x, game->y);
		game->x += 1;
		game->arr[game->x + 1][game->y] = 'P';
	}
	else if(game->arr[game->x - 1][game -> y] == 'E')
		check_door(game, key);
}


void go_left(int key, t_list *game)
{
	if (game->arr[game->x][game->y - 1] != '1'
		&& game->arr[game->x][game->y - 1] != 'E')
	{
		if(game->arr[game->x][game->y - 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		img(game, game->x, game->y);
		game->y -= 1;
		game->arr[game->x][game->y - 1] = 'P';
	}
	else if(game->arr[game->x - 1][game -> y] == 'E')
		check_door(game, key);
}

void go_right(int key, t_list *game)
{
	if (game->arr[game->x][game->y + 1] != '1'
		&& game->arr[game->x][game->y + 1] != 'E')
	{
		if(game->arr[game->x][game->y + 1] == 'C')
			game->coins -= 1;
		game->arr[game->x][game->y] = '0';
		img(game, game->x, game->y);
		game->y += 1;
		game->arr[game->x][game->y + 1] = 'P';
	}
	else if(game->arr[game->x - 1][game -> y] == 'E')
		check_door(game, key);
}


int move_p(int key, t_list *game)
{
	if(key == 2 || key == 124)
	{
		go_right(key, game);
	}
	if(key == 0 || key == 123)
	{
		go_left(key, game);
	}
	if(key == 13 || key == 126)
	{
		go_up(key, game);
	}
	if(key == 1 || key == 125)
	{
		go_down(key, game);
	}
	if(key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_clear_window(game->mlx, game->win);
		exit(0);
	}
	return(0);
}

// void c_exit(t_list *game)
// {
// 	if(game->coins == 0)
// 		mlx_put_image_to_window(game->mlx, game ->win, game->open_door_img, game->a * 64, game->b * 64);
// 	else if(game->coins != 0)
// 		mlx_put_image_to_window(game->mlx, game ->win, game->close_door_img, game->a * 64, game->b * 64);
// }




int main(int argc, char **argv)
{
	t_list	game;
	(void)argc;
	int i = 0;
	int j = 0;
	int a = 0;

	if(check_ber(argv) == 1)//esi araj check_ber(game->fd, argv) voric heto bass erorr
		game.fd = open(argv[1], O_RDONLY);
	game.res = process_file(game.fd);//mekel esi dzeluc heto darav bass error
	game.q = ft_strtrim(game.res,"\n");
	game.arr = check(game.q);
	check_row(game.arr);
	check_column(game.arr);
	check_utils2(game.arr);
	check_utils(game.arr);
	width(game.arr, &game);
	height(game.arr, &game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "Hello world!");
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", &game.i, &game.j);
	game.background = mlx_xpm_file_to_image(game.mlx, "images/bg.xpm", &game.i, &game.j);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "images/player.xpm", &game.i, &game.j);
	game.coin_img = mlx_xpm_file_to_image(game.mlx, "images/coin.xpm", &game.i, &game.j);
	game.open_door_img = mlx_xpm_file_to_image(game.mlx, "images/open_door.xpm", &game.i, &game.j);
	game.close_door_img = mlx_xpm_file_to_image(game.mlx, "images/close_door.xpm", &game.i, &game.j);
	img(&game,game.x,game.y);
	// while(game.arr[game.h])
	// {
	// 	game.k = 0;
	// 	while(game.arr[game.h][game.k])
	// 	{
	// 		if (game.arr[game.h][game.k] == '1')
	// 			mlx_put_image_to_window(game.mlx, game.mlx_win, game.wall_img, game.k * 64, game.h * 64);
	// 		if (game.arr[game.h][game.k] == 'P')
	// 			mlx_put_image_to_window(game.mlx, game.mlx_win, game.player_img, game.k * 64, game.h * 64);
	// 		if (game.arr[game.h][game.k] == 'C')
	// 			mlx_put_image_to_window(game.mlx, game.mlx_win, game.coin_img, game.k * 64, game.h * 64);
	// 		if (game.arr[game.h][game.k] == 'E')
	// 			mlx_put_image_to_window(game.mlx, game.mlx_win, game.close_door_img, game.k * 64, game.h * 64);
	// 		game.k++;
	// 	}
	// 	game.h++;
	// }
	mlx_hook(game.mlx_win, 2, 1L << 0, move_p, &game);
	mlx_loop(game.mlx);
	return 0;
}
