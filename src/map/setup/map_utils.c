/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:49:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/03 16:26:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"

int	count_columns(char **matrix)
{
	int	counter;

	if (!matrix)
		return (0);
	counter = 0;
	while (matrix[counter])
		counter++;
	return (counter);
}

int	is_digit_str(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
