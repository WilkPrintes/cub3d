/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:23:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 19:02:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	rerender_image(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img, 0, 0);
	return (0);
}

void	plot_pixel(t_core *core, t_vec2 pos, int color)
{
	char	*pixel;

	if (pos.x < 0 || pos.y < 0
		|| pos.x >= WINDOW_WIDTH || pos.y >= WINDOW_HEIGHT)
		return ;
	pixel = core->graphic.image.addr + (pos.y * core->graphic.image.line_size
			+ pos.x * (core->graphic.image.bpp / 8));
	*(unsigned int *)pixel = color;
}

int	ft_mlx_pixel_get(t_image *img, int x, int y)
{
	char	*byte;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	byte = img->addr + ((y * img->line_size) + (x * img->bpp / 8));
	return (*(unsigned int *)byte);
}

t_vec2	vec2(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
