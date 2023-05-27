/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:39:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/26 23:30:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook.h"

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

int	get_key(int key, t_core *core)
{
	if (key == KEY_ESC)
	{
		mlx_loop_end(core->graphic.mlx);
		return (1);
	}
	if (key == KEY_A)
		core->map.player.dir += 0.05;
	if (key == KEY_D)
		core->map.player.dir -= 0.05;
	if (key == KEY_W)
	{
		core->map.player.pos.x += 5 * cos(core->map.player.dir);
		core->map.player.pos.y -= 5 * sin(core->map.player.dir);
	}
	if (key == KEY_S)
	{
		core->map.player.pos.x -= 5 * cos(core->map.player.dir);
		core->map.player.pos.y += 5 * sin(core->map.player.dir);
	}
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		raycasting(core, core->map.player);
	return (0);
}
