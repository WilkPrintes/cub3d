/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:10:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/10 17:08:53 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"

static char *get_str_map(int map_fd, t_map *map);

int read_map(int map_fd, t_map *map)
{
	char *str_map;
	char **str_matrix;

	str_map = get_str_map(map_fd, map);
	close(map_fd);
	if (!str_map)
		return (map_error(0, NULL, "Invalid map size"));
	str_matrix = ft_split(str_map, '\n');
	free(str_map);
	if (!str_matrix)
		return (map_error(0, NULL, "Invalid map"));
	if (!get_int_map(str_matrix, map))
	{
		ft_free_char_matrix(&str_matrix);
		return (map_error(0, NULL, "Invalid character"));
	}
	ft_free_char_matrix(&str_matrix);
	if (map->player.x == 0 || map->player.y == 0)
		return (map_error(0, NULL, "Invalid map: no initial player position"));
	if (!is_closed_map(*map))
		return (map_error(0, NULL, "Invalid map: map isn't closed"));
	return (1);
}

static char *get_str_map(int map_fd, t_map *map)
{
	char *line;
	char *str_map;

	line = get_next_line(map_fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(map_fd);
	}
	str_map = line;
	while (line)
	{
		line = get_next_line(map_fd);
		if (!line)
			break;
		if (*line != '\n')
			map->lines++;
		if ((size_t)map->columns < ft_strlen(line) - 1)
			map->columns = ft_strlen(line) - 1;
		str_map = ft_strmerge(str_map, line);
	}
	return (str_map);
}
