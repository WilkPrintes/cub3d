/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:01:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 18:29:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	is_wall(double ay, double ax, t_map map)
{
	if (ay / 64 < 0 || ax / 64 < 0
		|| ay / 64 >= map.lines || ax / 64 >= map.columns)
		return (-1);
	if (map.matrix[(int)ay / 64][(int)ax / 64] == 1)
		return (1);
	return (0);
}

void	texturize_wall_h(t_core *core, t_vec2 i, t_vec2 pos, t_ray ray)
{
	int	text_x;
	int	text_y;

	if (sin(core->ray.angle) < 0)
	{
		text_x = (int)(
				core->map.player.pos.x + ray.distH * cos(ray.angle)) % 32;
		text_y = ((core->ray.s_texture.bpp)
				* (i.y - (WINDOW_HEIGHT - ray.dist) / 2)) / ray.dist;
		text_x = text_x % core->ray.s_texture.bpp;
		plot_pixel(core, (t_vec2){pos.x, i.y},
			ft_mlx_pixel_get(&core->ray.s_texture, text_x, text_y));
	}
	else
	{
		text_x = (int)(
				core->map.player.pos.x + ray.distH * cos(ray.angle)) % 32;
		text_y = ((core->ray.n_texture.bpp)
				* (i.y - (WINDOW_HEIGHT - ray.dist) / 2)) / ray.dist;
		text_x = text_x % core->ray.n_texture.bpp;
		plot_pixel(core, (t_vec2){pos.x, i.y},
			ft_mlx_pixel_get(&core->ray.n_texture, text_x, text_y));
	}
}