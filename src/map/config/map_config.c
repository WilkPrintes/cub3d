/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:33:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/11 17:35:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"

static int	is_done(t_graphic_config config);
static void	free_line_and_words(char *line, char **words);
static void	getter(int *error, char *line, char **words,
				t_graphic_config *config);

int	get_graphic_config(int map_fd, t_graphic_config *config)
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
		getter(&error, line, words, config);
	}
	if (!is_done(*config) || error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	getter(int *error, char *line, char **words,
				t_graphic_config *config)
{
	if (count_columns(words) == 0)
	{
		free_line_and_words(line, words);
		return ;
	}
	if (count_columns(words) == 1)
	{
		free_line_and_words(line, words);
		*error = 1;
		return ;
	}
	if (*error || !get_colors(line, words, config))
	{
		if (count_columns(words) != 2)
			*error = map_error(1, words[0], "Too many arguments");
		if (!get_textures(words, &config->textures) && !is_done(*config))
			*error = 1;
	}
	free_line_and_words(line, words);
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

static void	free_line_and_words(char *line, char **words)
{
	ft_free_char_matrix(&words);
	free(line);
}
