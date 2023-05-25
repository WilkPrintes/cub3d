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

void	plot_pixel(t_core *core, t_vec2 pos, int color)
{
	char    *pixel;

	pixel = core->addr + (pos.y * core->line_length + pos.x * (core->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	print_sky_and_floor(t_core *core)
{
	create_rectangle(core, (t_vec2){0, 0}, (t_vec2){WIDTH, HEIGHT / 2}, 0x0000FF);
	create_rectangle(core, (t_vec2){0, HEIGHT / 2}, (t_vec2){WIDTH, HEIGHT / 2}, 0x808080);
}

// t_vec2	show_minimap(t_core *core, int map[10][10])
t_vec2	show_minimap(t_core *core, t_map map)
{
	t_vec2	i;
	t_vec2	player_pos;

	i.y = 0;
	i.x = 0;
	while (i.y < map.lines)
	{
		i.x = 0;
		while (i.x < map.columns)
		{
			if (map.matrix[i.y][i.x] == 2){
				player_pos = vec2(i.x * 64 + 32, i.y * 64);
				map.matrix[i.y][i.x] = 0;
			}
			i.x++;
		}
		i.y++;
	}
	(void)core;/////
	return (player_pos);
}

// int	is_wall(double ay, double ax, int map[10][10])
int	is_wall(double ay, double ax, int **map)
{
	if (ay / 64 < 0 || ax / 64 < 0 || ay / 64 > 9 || ax / 64 > 9)
		return (-1);
	if (map[(int)ay / 64][(int)ax / 64] == 1)
		return (1);
	return (0);
}

// t_vec2	dist_horizontal(int map[10][10], t_player player, double angle, t_core *core)
t_vec2	dist_horizontal(int **map, t_player player, double angle, t_core *core)
{
	double	ay;
	double	ax;
	double	ya;
	double	xa;

	(void)core;/////
	if (sin(angle) == 0)
		return (vec2(999999, 999999));
	if (sin(angle) > 0)
	{
		ay = floor(player.pos.y / 64) * 64 - 0.0001;
		ax = player.pos.x + (player.pos.y - ay) / tan(angle);
		ya = -64;
		xa =  64 / tan(angle);
		while (is_wall(ay, ax, map) == 0)
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
		while (is_wall(ay, ax, map) == 0)
		{
			ay += ya;
			ax += xa;
		}
		return (vec2((int)ax, (int)ay));
	}
}


// t_vec2	dist_vert(int map[10][10], t_player player, double angle, t_core *core)
t_vec2	dist_vert(int **map, t_player player, double angle, t_core *core)
{
	double	bx;
	double	by;
	double	xa;
	double	ya;

	(void)core;//////
	if (cos(angle) == 0)
		return (vec2(999999, 999999));
	if (cos(angle) > 0)
	{
		bx = floor(player.pos.x / 64) * 64 + 64;
		by =  player.pos.y + (player.pos.x - bx) * tan(angle);
		ya =  -64 * tan(angle);
		xa = 64;
		while (is_wall(by, bx, map) == 0)
		{
			by += ya;
			bx += xa;
		}
		return (vec2((int)bx, (int)by));
	}
	else
	{
		bx = floor(player.pos.x / 64) * 64 - 0.0001;
		by =  player.pos.y + (player.pos.x - bx) * tan(angle);
		ya = 64 * tan(angle);
		xa = -64;
		while (is_wall(by, bx, map) == 0)
		{
			by += ya;
			bx += xa;
		}
		return (vec2((int)bx, (int)by));
	}
}

t_vec2	vec2(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

void	create_rectangle(t_core *core, t_vec2 pos, t_vec2 size, int color)
{
	t_vec2 	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			plot_pixel(core, (t_vec2){pos.x + i.x, pos.y + i.y}, color);
			i.x++;
		}
		i.y++;
	}
}

double	wall_projection(double dist_wall)
{
	double	wall_height;

	if (dist_wall == 0 || dist_wall == 999999)
		return (0);
	wall_height = 64 / dist_wall * HEIGHT;
	if (wall_height > HEIGHT)
		return (HEIGHT);
	return (wall_height);
}

void	create_wall(t_core *core, t_vec2 pos, double wall_height, int color)
{
	t_vec2 	i;
	int		start;
	int 	end;

	start = (HEIGHT - wall_height) / 2;
	end = (HEIGHT + wall_height) / 2;
	i.y = 0;
	while (i.y < HEIGHT)
	{
		if (i.y < start)
			plot_pixel(core, (t_vec2){pos.x, i.y}, 0x0000FF);
		else if (i.y > end)
			plot_pixel(core, (t_vec2){pos.x, i.y}, 0x808080);
		else
			plot_pixel(core, (t_vec2){pos.x, i.y}, color);
		i.y++;
	}
}
