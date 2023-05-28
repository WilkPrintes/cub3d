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

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "define.h"
# include "macro.h"
# include "render.h"
# include "wall.h"

// raycasting.c
void	raycasting(t_core *core, t_player player);

// distance.c
t_vec2	dist_horizontal(t_player player, double angle, t_core *core);
t_vec2	dist_vert(t_player player, double angle, t_core *core);

#endif
