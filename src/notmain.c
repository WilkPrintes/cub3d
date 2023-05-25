/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:18:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/25 03:09:22 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"
#include "map.h"

static int	mlx_runner(int floor_color, int ceiling_color);

int	notmain(int argc, char **argv)
{
	t_graphic_config	config;
	t_map				map;

	if (param_verifier(argc, argv[1]))
		return (1);
	if (!get_map(argv[1], &map, &config))
		return (EXIT_FAILURE);
	return (mlx_runner(config.floor_rgb, config.ceiling_rgb));
}

static int	mlx_runner(int floor_color, int ceiling_color)
{
	t_mlx_data	data;

	data = mount_mlx("prototype");
	if (data_verifier(&data))
		return (1);
	paint_rectangle(&data.image,
		(t_pixel){.x = WINDOW_WIDTH, .y = 0},
		(t_pixel){.x = 0, .y = WINDOW_HEIGHT / 2},
		ceiling_color);
	paint_rectangle(&data.image,
		(t_pixel){.x = 0, .y = WINDOW_HEIGHT},
		(t_pixel){.x = WINDOW_WIDTH, .y = WINDOW_HEIGHT / 2},
		floor_color);
	mlx_put_image_to_window(data.mlx, data.win, data.image.mlx_img, 0, 0);
	mlx_hook(data.win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK,
		&key_press_hook, &data);
	mlx_hook(data.win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
		&mouse_hook, &data);
	mlx_expose_hook(data.win, &rerender_image, &data);
	mlx_loop(data.mlx);
	return (dismount_mlx(&data));
}
