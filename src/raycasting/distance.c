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
