/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:08:08 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 13:08:09 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check(char *q)
{
	int		i;
	char	**arr;

	i = 0;
	while (q[i] != '\0')
	{
		if (q[i] == '\n' && q[i + 1] == '\n')
		{
			printf("ERROR");
			exit(1);
		}
		i++;
	}
	arr = ft_split(q, '\n');
	check_verevini_sharunakutyun(arr);
	return (arr);
}

char	**check_verevini_sharunakutyun(char **arr)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen1(arr[0]);
	while (arr[i])
	{
		if (ft_strlen1(arr[i]) != n)
		{
			printf("Error1");
			exit (1);
		}
		i++;
	}
	return (arr);
}

int	matrix_column(char **arr)
{
	int	column;

	column = 0;
	while (arr[0][column])
		column++;
	return (column);
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
		if (arr[0][i] != '1' || arr[len - 1][i] != '1')
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
