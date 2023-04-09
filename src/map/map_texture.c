/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:43:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/04/08 22:55:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_texture.h"

static void	populate_path(char *new_path, char **texture_path);
static int	count_columns(char **matrix);

int	get_textures(char **words, t_texture_path *textures)
{
	if (count_columns(words) != 2)
		return (0);
	if (file_access_verifier(words[1]))
		return (0);
	if (ft_strcmp(NORTH_WALL_TEXTURE_ID, words[0]) == 0)
		populate_path(words[1], &textures->north_wall);
	else if (ft_strcmp(SOUTH_WALL_TEXTURE_ID, words[0]) == 0)
		populate_path(words[1], &textures->south_wall);
	else if (ft_strcmp(EAST_WALL_TEXTURE_ID, words[0]) == 0)
		populate_path(words[1], &textures->east_wall);
	else if (ft_strcmp(WEST_WALL_TEXTURE_ID, words[0]) == 0)
		populate_path(words[1], &textures->west_wall);
	else
		return (0);
	return (1);
}

static void	populate_path(char *new_path, char **texture_path)
{
	if (!texture_path || !new_path)
		return ;
	if (*texture_path)
		ft_null_free((void **)texture_path);
	*texture_path = ft_strdup(new_path);
}

static int	count_columns(char **matrix)
{
	int	counter;

	if (!matrix)
		return (0);
	counter = 0;
	while (matrix[counter])
		counter++;
	return (counter);
}
