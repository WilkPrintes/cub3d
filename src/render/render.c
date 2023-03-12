/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:23:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:36:00 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	paint_pixel_in_image(t_image *image, t_pixel p);

int	rerender_image(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img, 0, 0);
	return (0);
}

void	paint_rectangle(t_image *image,
	t_pixel start_corner, t_pixel end_corner, int color)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;

	delta_x = 1;
	delta_y = 1;
	if (start_corner.x > end_corner.x)
		delta_x = -1;
	if (start_corner.y > end_corner.y)
		delta_y = -1;
	x = start_corner.x;
	while (x != end_corner.x + delta_x)
	{
		y = start_corner.y;
		while (y != end_corner.y + delta_y)
		{
			paint_pixel_in_image(image,
				(t_pixel){.x = x, .y = y, .color = color});
			y += delta_y;
		}
		x += delta_x;
	}
}

static void	paint_pixel_in_image(t_image *image, t_pixel p)
{
	char	*pixel;
	int		i;

	if (p.x < 0 || p.x >= WINDOW_WIDTH || p.y < 0 || p.y >= WINDOW_HEIGHT)
		return ;
	pixel = image->addr + p.x * (image->bpp / 8) + p.y * image->line_size;
	if (image->endian == 0)
	{
		i = 0;
		while (i < image->bpp)
		{
			*pixel++ = (p.color >> (sizeof(p.color) * 8 - image->bpp + i))
				& 0xFF;
			i += 8;
		}
	}
	else
	{
		i = 8;
		while (i <= image->bpp)
		{
			*pixel++ = (p.color >> (sizeof(p.color) * 8 - i)) & 0xFF;
			i += 8;
		}
	}
}
