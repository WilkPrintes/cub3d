/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:43:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/25 16:00:23 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_setup.h"

static int	populate_path(char *new_path, char **texture_path);

int	get_textures(char **words, t_texture_path *textures)
{
	if (ft_strcmp(NORTH_WALL_TEXTURE_ID, words[0]) == 0)
		return (populate_path(words[1], &textures->north_wall));
	else if (ft_strcmp(SOUTH_WALL_TEXTURE_ID, words[0]) == 0)
		return (populate_path(words[1], &textures->south_wall));
	else if (ft_strcmp(EAST_WALL_TEXTURE_ID, words[0]) == 0)
		return (populate_path(words[1], &textures->east_wall));
	else if (ft_strcmp(WEST_WALL_TEXTURE_ID, words[0]) == 0)
		return (populate_path(words[1], &textures->west_wall));
	else
		return (0);
}

void	free_texture_paths(t_texture_path *textures)
{
	ft_null_free((void **)&textures->north_wall);
	ft_null_free((void **)&textures->south_wall);
	ft_null_free((void **)&textures->east_wall);
	ft_null_free((void **)&textures->west_wall);
}

static int	populate_path(char *new_path, char **texture_path)
{
	if (!texture_path || !new_path)
		return (0);
	if (*texture_path)
		return (0);
	*texture_path = ft_strdup(new_path);
	if (file_access_verifier(new_path))
		return (0);
	return (1);
}
