/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:30:58 by handrias          #+#    #+#             */
/*   Updated: 2023/01/26 14:32:49 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	len(int n)
{
	int	si;

	si = 1;
	if (n > 9)
	{
		while (n > 9)
		{
			n = n / 10;
			si++;
		}
	}
	else if (n < 0)
	{
		while (n < -9)
		{
			n = n / 10;
			si++;
		}
		si++;
	}
	return (si);
}

char	*neg(int n)
{
	char	*j;
	int		i;

	i = len(n);
	j = malloc(i + 1);
	if (j == 0)
		return (NULL);
	j[0] = '-';
	j[i] = '\0';
	while (i > 1)
	{
		i--;
		j[i] = -(n % 10) + 48;
		n = n / 10;
	}
	return (j);
}

char	*pos(int n)
{
	char	*j;
	int		i;

	i = len(n);
	j = malloc(i + 1);
	if (j == 0)
		return (NULL);
	j[i] = '\0';
	while (i > 0)
	{
		i--;
		j[i] = n % 10 +48;
		n = n / 10;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (neg(n));
	else
		return (pos(n));
	return (0);
}
