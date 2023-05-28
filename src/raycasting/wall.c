/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:00:59 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 17:03:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double wall_projection(double dist_wall)
{
	double wall_height;

	if (dist_wall == 0 || dist_wall == 999999)
		return (0);
	wall_height = 64 / dist_wall * WINDOW_HEIGHT;
	return (wall_height);
}

void create_wall_v(t_core *core, t_vec2 pos, double wall_height, double dist_wall, double angle)
{
	t_vec2 i;
	int start;
	int end;
	int text_x = 0;
	int text_y = 0;

	start = (WINDOW_HEIGHT - wall_height) / 2;
	end = (WINDOW_HEIGHT + wall_height) / 2;
	i.y = 0;
	while (i.y < WINDOW_HEIGHT)
	{
		if (i.y < start)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.ceiling_rgb);
		else if (i.y > end)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.floor_rgb);
		else
		{
			if (cos(core->ray.angle) < 0)
			{
				text_x = (int)floor(core->map.player.pos.y - dist_wall * sin(angle)) % 32;
				text_y = ((core->ray.w_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.w_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.w_texture, text_x, text_y));
			}
			else
			{
				text_x = (int)floor(core->map.player.pos.y - dist_wall * sin(angle)) % 32;
				text_y = ((core->ray.e_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.e_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.e_texture, text_x, text_y));
			}
		}
		i.y++;
	}
}

void create_wall_h(t_core *core, t_vec2 pos, double wall_height, double dist_wall, double angle)
{
	t_vec2 i;
	int start;
	int end;
	int text_x = 0;
	int text_y = 0;

	start = (WINDOW_HEIGHT - wall_height) / 2;
	end = (WINDOW_HEIGHT + wall_height) / 2;
	i.y = 0;
	while (i.y < WINDOW_HEIGHT)
	{
		if (i.y < start)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.ceiling_rgb);
		else if (i.y > end)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.floor_rgb);
		else
		{
			if (sin(core->ray.angle) < 0)
			{
				text_x = (int)(core->map.player.pos.x + dist_wall * cos(angle)) % 32;
				text_y = ((core->ray.s_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.s_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.s_texture, text_x, text_y));
			}
			else
			{
				text_x = (int)(core->map.player.pos.x + dist_wall * cos(angle)) % 32;
				text_y = ((core->ray.n_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.n_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.n_texture, text_x, text_y));
			}
		}
		i.y++;
	}
}
