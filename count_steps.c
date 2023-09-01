/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:43:23 by handrias          #+#    #+#             */
/*   Updated: 2023/08/11 16:43:25 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_steps(t_list *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	printf("%s\n", str);
	free (str);
	return (0);
}
