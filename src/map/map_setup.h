/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:43:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/11 17:51:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SETUP_H
# define MAP_SETUP_H

# include <stdlib.h>
# include "macro.h"
# include "define.h"
# include "libft.h"
# include "error.h"
# include "verifier.h"

// Config
// map_config.c
int	get_graphic_config(int map_fd, t_graphic_config *config);
// map_color.c
int	get_colors(char *line, char **words, t_graphic_config *config);
// map_texture.c
int	get_textures(char **words, t_texture_path *textures);

// Matrix
// map_matrix.c
int	get_int_map(char **str_matrix, t_map *map);
// map_read.c
int	read_map(int map_fd, t_map *map);

// Miscellaneous
// map_verifier.c
int	is_closed_map(t_map map);
// map_utils.c
int	count_columns(char **matrix);
int	is_digit_str(const char *str);

#endif
