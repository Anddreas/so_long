/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:40:32 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 11:40:35 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_utils(char **arr, t_list *game)
{
	int	i;
	int	j;

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
	check_utils_sharunakutyun(arr, game);
}

void	check_utils_sharunakutyun(char **arr, t_list *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				game->x = i;
				game->y = j;
				x = i;
				y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	matrix_rows(char **arr)
{
	int	row;

	row = 0;
	while (arr[row])
		row++;
	return (row);
}

void	check_utils2(char **arr)
{
	int	has_e;
	int	has_p;
	int	has_c;

	has_e = 0;
	has_p = 0;
	has_c = 0;
	check_symbols(arr, &has_e, &has_p, &has_c);
	check_missing_symbols(has_e, has_p, has_c);
}

void	check_symbols(char **arr, int *hasE, int *hasP, int *hasC)
{
	int	i;
	int	j;

	i = 0;
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
