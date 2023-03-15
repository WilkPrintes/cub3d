/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:18:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:38:18 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"

static int	mlx_runner(void);

int	main(int argc, char **argv)
{
	if (param_verifier(argc, argv[1]))
		return (1);
	return (mlx_runner());
}

static int	mlx_runner(void)
{
	t_mlx_data	data;

	data = mount_mlx("prototype");
	if (data_verifier(&data))
		return (1);
	paint_rectangle(&data.image,
		(t_pixel){.x = WINDOW_WIDTH, .y = 0},
		(t_pixel){.x = 0, .y = WINDOW_HEIGHT / 2},
		0xFF);
	paint_rectangle(&data.image,
		(t_pixel){.x = 0, .y = WINDOW_HEIGHT},
		(t_pixel){.x = WINDOW_WIDTH, .y = WINDOW_HEIGHT / 2},
		0x22);
	mlx_put_image_to_window(data.mlx, data.win, data.image.mlx_img, 0, 0);
	mlx_hook(data.win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK,
		&key_press_hook, &data);
	mlx_hook(data.win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
		&mouse_hook, &data);
	mlx_expose_hook(data.win, &rerender_image, &data);
	mlx_loop(data.mlx);
	return (dismount_mlx(&data));
}
