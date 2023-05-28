/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:36:59 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 20:24:59 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <math.h>
# include "macro.h"
# include "define.h"
# include "render.h"

// wall.c
void	create_wall_h(t_core *core, t_vec2 pos, t_ray ray);
void	create_wall_v(t_core *core, t_vec2 pos, t_ray ray);
double	wall_projection(double dist_wall);

// wall_utils.c
int		is_wall(double ay, double ax, t_map map);
void	texturize_wall_h(t_core *core, t_vec2 i, t_vec2 pos, t_ray ray);
void	texturize_wall_v(t_core *core, t_vec2 i, t_vec2 pos, t_ray ray);

#endif
