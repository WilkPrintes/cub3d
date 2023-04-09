/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:43:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/04/08 22:55:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEXTURE_H
# define MAP_TEXTURE_H

# include <stdlib.h>
# include <fcntl.h>
# include "macro.h"
# include "define.h"
# include "libft.h"

int	get_textures(char **words, t_texture_path *textures);

#endif
