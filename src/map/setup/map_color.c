/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:45:07 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/11 16:41:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"

static int	is_valid_rgb(char **rgb_array);
static int	rgb_to_int(int red, int green, int blue);
static int	populate_color(char *comma_separated_rgb, int *color);

int	get_colors2(char *line, char **words, t_graphic_config *config)
{
	char	*rgb_start;

	// rgb_start = ft_strnstr(line, FLOOR_COLOR_ID, ft_strlen(line));
	// if (!rgb_start)
	// 	rgb_start = ft_strnstr(line, CEILING_COLOR_ID, ft_strlen(line));
	// printf("\nwords[1]: %s\n", words[1]);
	rgb_start = ft_strnstr(line, words[1], ft_strlen(line));

	if (!rgb_start)
	{
		return (0);
	}
	// if (!ft_isspace(rgb_start + 1) || ft_strncmp(words[0], rgb_start, 1))
	// 	return (map_error(0, line, "Invalid configuration"));

	// printf("words[1]: %s\n", words[1]);
	// printf("rgb_start: %s\n", rgb_start);
	// printf("Start\t");
	if (ft_strcmp(FLOOR_COLOR_ID, words[0]) == 0)
		return (populate_color(rgb_start, &config->floor_rgb));
	else if (ft_strcmp(CEILING_COLOR_ID, words[0]) == 0)
		return (populate_color(rgb_start, &config->ceiling_rgb));
	return (0);
}

// static int	is_valid_rgb2(char **rgb_array)
// {
// 	char	*trimmed_str;
// 	int		index;

// 	if (count_columns(rgb_array) != 3)
// 		return (0);
// 	index = 0;
// 	while (rgb_array[index])
// 	{
// 		trimmed_str = ft_strtrim(rgb_array[index], " \f\n\r\t\v");
// 		if (ft_strlen(trimmed_str) > 3 || !is_digit_str(trimmed_str)
// 			|| ft_atoi(trimmed_str) < 0 || ft_atoi(trimmed_str) > 255)
// 		{
// 			free(trimmed_str);
// 			return (0);
// 		}
// 		free(trimmed_str);
// 		index++;
// 	}
// 	return (1);
// }

int	get_colors(char **words, t_graphic_config *config)
{
	if (ft_strcmp(FLOOR_COLOR_ID, words[0]) == 0)
		return (populate_color(words[1], &config->floor_rgb));
	else if (ft_strcmp(CEILING_COLOR_ID, words[0]) == 0)
		return (populate_color(words[1], &config->ceiling_rgb));
	return (0);
}

static int	rgb_to_int(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	is_valid_rgb(char **rgb_array)
{
	char	*trimmed_str;
	int		index;

	if (count_columns(rgb_array) != 3)
		return (0);
	index = 0;
	while (rgb_array[index])
	{
		trimmed_str = ft_strtrim(rgb_array[index], " \f\n\r\t\v");
		if (ft_strlen(trimmed_str) > 3 || !is_digit_str(trimmed_str)
			|| ft_atoi(trimmed_str) < 0 || ft_atoi(trimmed_str) > 255)
		{
			free(trimmed_str);
			return (0);
		}
		free(trimmed_str);
		index++;
	}
	return (1);
}

static int	populate_color(char *comma_separated_rgb, int *color)
{
	char	**rgb_array;

	// printf("Middle\t");
	if (!comma_separated_rgb)
		return (map_error(0, comma_separated_rgb, "Invalid RGB value"));
	if (ft_strnstr(comma_separated_rgb, ",,", ft_strlen(comma_separated_rgb))
		|| !ft_isdigit(comma_separated_rgb[0]))
		// || !ft_isdigit(comma_separated_rgb[ft_strlen(comma_separated_rgb) - 1]))
		return (map_error(0, comma_separated_rgb, "Invalid RGB value"));
	if (*color != -1)
		return (map_error(0, NULL, "Invalid double attribution"));
	rgb_array = ft_split(comma_separated_rgb, ',');
	if (is_valid_rgb(rgb_array))
	{
		*color = rgb_to_int(
				ft_atoi(rgb_array[0]),
				ft_atoi(rgb_array[1]),
				ft_atoi(rgb_array[2]));
		ft_free_char_matrix(&rgb_array);
		// printf("End\n");
		return (1);
	}
	map_error(0, comma_separated_rgb, "Invalid RGB value");
	ft_free_char_matrix(&rgb_array);
	return (0);
}
