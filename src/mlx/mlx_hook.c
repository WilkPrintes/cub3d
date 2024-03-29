/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:39:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 17:26:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook.h"

static void	force_map_limits(t_core *core);
static void	wasd_key_hook(int key, t_core *core);

int	mouse_hook(t_mlx_data *data)
{
	mlx_loop_end(data->mlx);
	return (1);
}

int	key_press_hook(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (0);
}

int	keypress_hook(int key, t_core *core)
{
	if (key == KEY_ESC)
	{
		mlx_loop_end(core->graphic.mlx);
		return (1);
	}
	if (key == LEFT_ARROW_KEY)
		core->map.player.dir += 0.05;
	if (key == RIGHT_ARROW_KEY)
		core->map.player.dir -= 0.05;
	if (key == LEFT_ARROW_KEY || key == RIGHT_ARROW_KEY)
		raycasting(core, core->map.player);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
	{
		wasd_key_hook(key, core);
		force_map_limits(core);
		raycasting(core, core->map.player);
	}
	return (0);
}

static void	wasd_key_hook(int key, t_core *core)
{
	if (key == KEY_A)
	{
		core->map.player.pos.x += round(5 * cos(core->map.player.dir + PI / 2));
		core->map.player.pos.y -= round(5 * sin(core->map.player.dir + PI / 2));
	}
	if (key == KEY_D)
	{
		core->map.player.pos.x += round(5 * cos(core->map.player.dir - PI / 2));
		core->map.player.pos.y -= round(5 * sin(core->map.player.dir - PI / 2));
	}
	if (key == KEY_W)
	{
		core->map.player.pos.x += round(5 * cos(core->map.player.dir));
		core->map.player.pos.y -= round(5 * sin(core->map.player.dir));
	}
	if (key == KEY_S)
	{
		core->map.player.pos.x -= round(5 * cos(core->map.player.dir));
		core->map.player.pos.y += round(5 * sin(core->map.player.dir));
	}
}

static void	force_map_limits(t_core *core)
{
	if (core->map.player.pos.x < 0)
		core->map.player.pos.x = 0;
	if (core->map.player.pos.y < 0)
		core->map.player.pos.y = 0;
	if (core->map.player.pos.x > core->map.columns * 64 - 64)
		core->map.player.pos.x = core->map.columns * 64 - 64;
	if (core->map.player.pos.y > core->map.lines * 64 - 64)
		core->map.player.pos.y = core->map.lines * 64 - 64;
}
