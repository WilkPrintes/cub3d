/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:22 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"
#include "raycasting.h"

static int	get_player(int x, int y, char c, t_player *player);
static int	is_valid_map_char(int *value, char c);

int	get_int_map(char **str_matrix, t_map *map)
{
	int	x;
	int	y;
	int	error;

	map->matrix = malloc(map->lines * sizeof (int *));
	y = -1;
	error = 0;
	while (++y < map->lines)
	{
		x = -1;
		map->matrix[y] = malloc(map->columns * sizeof (int));
		while (++x < map->columns)
		{
			map->matrix[y][x] = -1;
			if (x >= (int)ft_strlen(str_matrix[y]))
				continue ;
			if (get_player(x, y, str_matrix[y][x], &map->player) == -1)
				error = 1;
			error |= !is_valid_map_char(&map->matrix[y][x], str_matrix[y][x]);
		}
	}
	return (!error);
}

static int	get_player(int x, int y, char c, t_player *player)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (player->pos.x || player->pos.y)
			return (-1);
		player->pos.x = x * 64 + 32;
		player->pos.y = y * 64 + 32;
		if (c == 'N')
			player->dir = PI / 2;
		if (c == 'S')
			player->dir = 3 * PI / 2;
		if (c == 'E')
			player->dir = 0;
		if (c == 'W')
			player->dir = PI;
		return (1);
	}
	return (0);
}

static int	is_valid_map_char(int *value, char c)
{
	char	*locale;

	if (c == '0' || c == '1')
		*value = c - 48;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		*value = 0;
	else if (ft_isspace(c))
		*value = -1;
	else
	{
		*value = -1;
		locale = malloc(2 * sizeof(char));
		locale[0] = c;
		locale[1] = '\0';
		map_error(0, locale, "Invalid character");
		free(locale);
		return (0);
	}
	return (1);
}
