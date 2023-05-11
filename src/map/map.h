/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:50:07 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/04 15:09:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include "macro.h"
# include "define.h"
# include "libft.h"
# include "error.h"
# include "map_setup.h"

int	fn(char *file, t_map *map, t_graphic_config *config);

#endif
