/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:21:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/24 23:21:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"
#include "map.h"

int is_wall(double ay, double ax, t_map map)
{
	if (ay / 64 < 0 || ax / 64 < 0 || ay / 64 >= map.lines || ax / 64 >= map.columns)
		return (-1);
	if (map.matrix[(int)ay / 64][(int)ax / 64] == 1)
		return (1);
	return (0);
}

t_vec2 dist_horizontal(t_player player, double angle, t_core *core)
{
	double ay;
	double ax;
	double ya;
	double xa;

	if (sin(angle) == 0)
		return (vec2(999999, 999999));
	if (sin(angle) > 0)
	{
		ay = floor(player.pos.y / 64) * 64 - 0.0001;
		ax = player.pos.x + (player.pos.y - ay) / tan(angle);
		ya = -64;
		xa = 64 / tan(angle);
		while (is_wall(ay, ax, core->map) == 0)
		{
			ay += ya;
			ax += xa;
		}
		return (vec2((int)ax, (int)ay));
	}
	else
	{

		ay = floor(player.pos.y / 64) * 64 + 64;
		ax = player.pos.x + (player.pos.y - ay) / tan(angle);
		ya = 64;
		xa = -64 / tan(angle);
		while (is_wall(ay, ax, core->map) == 0)
		{
			ay += ya;
			ax += xa;
		}
		return (vec2((int)ax, (int)ay));
	}
}

t_vec2 dist_vert(t_player player, double angle, t_core *core)
{
	double bx;
	double by;
	double xa;
	double ya;

	if (cos(angle) == 0)
		return (vec2(999999, 999999));
	if (cos(angle) > 0)
	{
		bx = floor(player.pos.x / 64) * 64 + 64;
		by = player.pos.y + (player.pos.x - bx) * tan(angle);
		ya = -64 * tan(angle);
		xa = 64;
		while (is_wall(by, bx, core->map) == 0)
		{
			by += ya;
			bx += xa;
		}
		return (vec2((int)bx, (int)by));
	}
	else
	{
		bx = floor(player.pos.x / 64) * 64 - 0.0001;
		by = player.pos.y + (player.pos.x - bx) * tan(angle);
		ya = 64 * tan(angle);
		xa = -64;
		while (is_wall(by, bx, core->map) == 0)
		{
			by += ya;
			bx += xa;
		}
		return (vec2((int)bx, (int)by));
	}
}

t_vec2 vec2(int x, int y)
{
	t_vec2 vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

double wall_projection(double dist_wall)
{
	double wall_height;

	if (dist_wall == 0 || dist_wall == 999999)
		return (0);
	wall_height = 64 / dist_wall * WINDOW_HEIGHT;
	if (wall_height > WINDOW_HEIGHT)
		return (WINDOW_HEIGHT);
	return (wall_height);
}

int ft_mlx_pixel_get(t_image *img, int x, int y)
{
	char *byte;

	byte = img->addr + ((y * img->line_size) + (x * img->bpp / 8));
	return (*(unsigned int *)byte);
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
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.floor_rgb);
		else if (i.y > end)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.ceiling_rgb);
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
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.floor_rgb);
		else if (i.y > end)
			plot_pixel(core, (t_vec2){pos.x, i.y}, core->config.ceiling_rgb);
		else
		{
			if (sin(core->ray.angle) < 0)
			{
				text_x = (int)floor(core->map.player.pos.x + dist_wall * cos(angle)) % 32;
				text_y = ((core->ray.n_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.n_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.n_texture, text_x, text_y));
			}
			else
			{
				text_x = (int)floor(core->map.player.pos.x + dist_wall * cos(angle)) % 32;
				text_y = ((core->ray.s_texture.bpp) * (i.y - (WINDOW_HEIGHT - wall_height) / 2)) / wall_height;
				text_x = text_x % core->ray.s_texture.bpp;
				plot_pixel(core, (t_vec2){pos.x, i.y}, ft_mlx_pixel_get(&core->ray.s_texture, text_x, text_y));
			}
		}
		i.y++;
	}
}