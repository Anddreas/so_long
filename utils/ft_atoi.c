/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:30 by handrias          #+#    #+#             */
/*   Updated: 2023/02/01 15:35:59 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	f(const char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	j = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		j = j * -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - 48;
			i++;
		}
		else
			return (0);
	}
	return (j * n);
}

int	ft_atoi(const char *str)
{
	if (!str)
		return (0);
	else
		return (f(str));
}
