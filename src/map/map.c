/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:45:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/25 16:00:09 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_map_config(t_map *map, t_graphic_config *config);

int	get_map(char *file, t_map *map, t_graphic_config *config)
{
	int		fd;
	int		error;
	char	*line;

	init_map_config(map, config);
	fd = open(file, O_RDONLY);
	if (get_graphic_config(fd, config) == EXIT_FAILURE)
	{
		map_error(0, NULL, "Invalid configuration");
		line = get_next_line(fd);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		free_texture_paths(&config->textures);
		return (0);
	}
	error = !read_map(fd, map);
	if (error)
	{
		free_texture_paths(&config->textures);
		ft_free_matrix((void *)&map->matrix, map->lines);
	}
	return (!error);
}

static void	init_map_config(t_map *map, t_graphic_config *config)
{
	config->floor_rgb = -1;
	config->ceiling_rgb = -1;
	config->textures = (t_texture_path){0};
	*map = (t_map){.lines = 1, .columns = 0, .matrix = NULL};
	map->player = (t_player){0};
}
