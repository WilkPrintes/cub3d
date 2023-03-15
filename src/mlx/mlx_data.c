/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:22:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:38:53 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_data.h"

t_mlx_data	mount_mlx(char *window_name)
{
	t_mlx_data	data;

	data = (t_mlx_data){0};
	data.mlx = mlx_init();
	if (!data.mlx)
		return (mlx_error(&data, "mlx_init", "Mlx setup failed."));
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			window_name);
	if (!data.win)
		return (mlx_error(&data, "mlx_new_window", "Mlx setup failed."));
	data.image.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.image.mlx_img)
		return (mlx_error(&data, "mlx_new_image", "Mlx setup failed."));
	data.image.addr = mlx_get_data_addr(data.image.mlx_img, &(data.image.bpp),
			&(data.image.line_size), &(data.image.endian));
	data.win_name = window_name;
	data.is_valid = 1;
	return (data);
}

int	dismount_mlx(t_mlx_data *data)
{
	if (!data->mlx)
		return (EXIT_FAILURE);
	mlx_loop_end(data->mlx);
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->image.mlx_img);
		mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (EXIT_SUCCESS);
}
