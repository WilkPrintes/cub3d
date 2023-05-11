/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:45:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/11 16:39:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	get_graphic_config(int map_fd, t_graphic_config *config);
static int	is_done(t_graphic_config config);
static void	free_texture_paths(t_texture_path *textures);

int	fn(char *file, t_map *map, t_graphic_config *config)
{
	config->floor_rgb = -1;
	config->ceiling_rgb = -1;
	config->textures = (t_texture_path){0};
	*map = (t_map){.lines = 1, .columns = 0, .matrix = NULL};
	map->player = (t_player){0};

	int fd = open(file, O_RDONLY);
	if (get_graphic_config(fd, config) == EXIT_FAILURE)
	{
		map_error(0, NULL, "Invalid configuration");
		char *line;

		line = get_next_line(fd);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		free_texture_paths(&config->textures);
		return (1);
	}
	int error = !read_map(fd, map);
	free_texture_paths(&config->textures);
	ft_free_matrix((void *)&map->matrix, map->lines);
	return (error);
}

static int	get_graphic_config(int map_fd, t_graphic_config *config)
{
	int		error;
	char	*line;
	char	**words;


	error = 0;
	while (!is_done(*config) && !error)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		words = ft_word_split(line, ft_isspace);
		if (count_columns(words) == 0)
		{
			ft_free_char_matrix(&words);
			free(line);
			continue;
		}
		if (count_columns(words) == 1)
		{
			ft_free_char_matrix(&words);
			free(line);
			return (EXIT_FAILURE);
		}
		//////
		// if (error || !get_colors(words, config))
		if (error || !get_colors2(line, words, config))
		{
			if (count_columns(words) != 2)
				error = map_error(1, words[0], "Too many arguments");
			if (!get_textures(words, &config->textures) && !is_done(*config))
				error = 1;
		}
		//////
		// if (count_columns(words) != 2)
		// 	error = map_error(1, words[0], "Too many arguments");
		// if (error || (!get_colors(words, config)
		// 	&& !get_textures(words, &config->textures) && !is_done(*config)))
		// 	error = 1;
		ft_free_char_matrix(&words);
		free(line);
	}
	// printf("ceiling_rgb %i\n", config->ceiling_rgb);
	// printf("floor_rgb %i\n", config->floor_rgb);
	if (!is_done(*config) || error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_done(t_graphic_config config)
{
	if (config.ceiling_rgb == -1 || config.floor_rgb == -1)
		return (0);
	if (!config.textures.north_wall || !config.textures.south_wall
		|| !config.textures.east_wall || !config.textures.west_wall)
		return (0);
	return (1);
}

static void	free_texture_paths(t_texture_path *textures)
{
	ft_null_free((void **)&textures->north_wall);
	ft_null_free((void **)&textures->south_wall);
	ft_null_free((void **)&textures->east_wall);
	ft_null_free((void **)&textures->west_wall);
}
