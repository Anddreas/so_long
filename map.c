#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// #include "get_next_line.h"
#include "so_long.h"
#include <mlx.h>


void	width(char **map, t_list *game)
{
    int	i;
    i = 0;
    while(map[0][i] != '\0')
        i++;
    game->width = i;
}
void	height(char **map, t_list *game)
{
    int	i;
    i = 0;
    while(map[i] != '\0')
        i++;
    game->height = i;
}
