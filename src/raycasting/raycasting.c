/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:25:11 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 20:13:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	get_base_distances(t_core *core, t_player player);

void	raycasting(t_core *core, t_player player)
{
	int	i;

	core->ray.angle = PI / 6 + player.dir;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		get_base_distances(core, player);
		if (core->ray.num_dist_h < core->ray.num_dist_v)
		{
			core->ray.dist = wall_projection(core->ray.num_dist_h);
			create_wall_h(core, vec2(i, core->ray.dist), core->ray);
		}
		else
		{
			core->ray.dist = wall_projection(core->ray.num_dist_v);
			create_wall_v(core, vec2(i, core->ray.dist), core->ray);
		}
		core->ray.angle -= PI / 3 / WINDOW_WIDTH;
		i++;
	}
	mlx_put_image_to_window(core->graphic.mlx, core->graphic.win,
		core->graphic.image.mlx_img, 0, 0);
}

static void	get_base_distances(t_core *core, t_player player)
{
	core->ray.dist_h = dist_horizontal(player, core->ray.angle, core);
	core->ray.dist_v = dist_vert(player, core->ray.angle, core);
	core->ray.num_dist_h = cos(player.dir - core->ray.angle) * sqrt(
			pow(core->ray.dist_h.x - player.pos.x, 2)
			+ pow(core->ray.dist_h.y - player.pos.y, 2));
	core->ray.num_dist_v = cos(player.dir - core->ray.angle) * sqrt(
			pow(core->ray.dist_v.x - player.pos.x, 2)
			+ pow(core->ray.dist_v.y - player.pos.y, 2));
}
