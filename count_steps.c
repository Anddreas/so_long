#include "so_long.h"

int count_steps(t_list *game)
{
	int		count;
	char	*str;

	str = ft_itoa(game->steps);
	printf("%s\n",str);
	free(str);
	return(0);
}
