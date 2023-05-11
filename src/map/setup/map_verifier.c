/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/10 17:08:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_wall_or_floor(int c);
static int	is_correctly_surrounded(int x, int y, t_map map);

int	is_closed_map(t_map map)
{
	int	x;
	int	y;
	int is_closed;

	y = 0;
	is_closed = 1;
	while (y < map.lines)
	{
		x = 0;
		while (x < map.columns)
		{
			if (map.matrix[y][x] == 0)
				is_closed = is_closed && is_correctly_surrounded(x, y, map);
			x++;
		}
		y++;
	}
	return (is_closed);
}

static int	is_wall_or_floor(int c)
{
	if (c == 0 || c == 1)
		return (1);
	return (0);
}

static int	is_correctly_surrounded(int x, int y, t_map map)
{
	if (x == 0 || x == map.columns - 1 || y == 0 || y == map.lines - 1)
		return (0);
	if (!is_wall_or_floor(map.matrix[y][x - 1])
		|| !is_wall_or_floor(map.matrix[y][x + 1])
		|| !is_wall_or_floor(map.matrix[y - 1][x])
		|| !is_wall_or_floor(map.matrix[y + 1][x])
		|| !is_wall_or_floor(map.matrix[y - 1][x - 1])
		|| !is_wall_or_floor(map.matrix[y - 1][x + 1])
		|| !is_wall_or_floor(map.matrix[y + 1][x - 1])
		|| !is_wall_or_floor(map.matrix[y + 1][x + 1]))
		return (0);
	return (1);
}
