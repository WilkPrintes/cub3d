/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:39:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:39:03 by bmugnol-         ###   ########.fr       */
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
