/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:31:38 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/26 23:31:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "define.h"
# include "macro.h"
# include "render.h"
# include "wall.h"
# include "map.h"

void	print_player(t_core *core, t_player player);
void	show_dir(t_core *core, t_player player, int **map);
t_vec2	dist_horizontal(t_player player, double angle, t_core *core);
t_vec2	dist_vert(t_player player, double angle, t_core *core);
double	wall_projection(double dist_wall);
void	raycasting(t_core *core, t_player player);

#endif
