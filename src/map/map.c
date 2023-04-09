/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:45:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/04/08 22:53:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	get_graphic_config(int map_fd, t_graphic_config *config);
static int	is_done(t_graphic_config config);
static void	free_texture_paths(t_texture_path *textures)
{
	ft_null_free((void **)&textures->north_wall);
	ft_null_free((void **)&textures->south_wall);
	ft_null_free((void **)&textures->east_wall);
	ft_null_free((void **)&textures->west_wall);
}
void	fn(void)
{
	t_graphic_config	config;

	int fd = open("maps/validMap.cub", O_RDONLY);
	printf("return: %i\n", get_graphic_config(fd, &config));
	printf("north: %s\n", config.textures.north_wall);
	printf("south: %s\n", config.textures.south_wall);
	printf("east: %s\n", config.textures.east_wall);
	printf("west: %s\n", config.textures.west_wall);
	close(fd);
	free_texture_paths(&config.textures);
}

static int	get_graphic_config(int map_fd, t_graphic_config *config)
{
	int		error;
	char	*line;
	char	**words;

	error = 0;
	config->floor_rgb = -1;
	config->ceiling_rgb = -1;
	config->textures = (t_texture_path){0};
	while (!is_done(*config) && !error)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		words = ft_word_split(line, ft_isspace);
		if (words && !words[0]) // column count  = 0
		{
			ft_free_char_matrix(&words);
			free(line);
			continue;
		}
		if (/*!get_colors(words, &config)*/
			/*&&*/!get_textures(words, &config->textures)
			&& !is_done(*config))
			error = 1;
		ft_free_char_matrix(&words);
		free(line);
	}
	while (line)
	{
		line = get_next_line(map_fd);
		free(line);
	}
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
