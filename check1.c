/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:50:36 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 11:50:39 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (to_find[len])
		len++;
	while (str[j] != '\0')
		j++;
	if (len < j)
	{
		while (i != 4)
		{
			if (str[j - 4] != to_find[i])
				return (0);
			j++;
			i++;
		}
		if (i == 4)
			return (1);
	}
	return (0);
}

int	check_ber(char **argv, t_list *game)
{
	char	**map;

	map = &argv[1];
	if (map == NULL)
		return (0);
	if (ft_strstr(*map, ".ber") == 1)
		return (1);
	else
		return (0);
}

char	*process_file(int a, t_list *game)
{
	char	*res;
	char	*line;
	char	*tmp;

	// *res = NULL;
	if (a < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(a);
		if (line == NULL)
			break ;
		if (!res)
			tmp = ft_strdup(line);
		else
			tmp = ft_strjoin(res, line);
		free(line);
		if (res)
			free(res);
		res = tmp;
	}
	if (res == NULL)
	{
		printf("Error reading file\n");
		exit(1);
	}
	return (res);
}
