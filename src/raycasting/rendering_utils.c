/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:34:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/26 23:35:12 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void print_sky_and_floor(t_core *core)
{
	create_rectangle(core, (t_vec2){0, 0}, (t_vec2){WINDOW_WIDTH, WINDOW_HEIGHT / 2}, 0x0000FF);
	create_rectangle(core, (t_vec2){0, WINDOW_HEIGHT / 2}, (t_vec2){WINDOW_WIDTH, WINDOW_HEIGHT / 2}, 0x808080);
}

void create_rectangle(t_core *core, t_vec2 pos, t_vec2 size, int color)
{
	t_vec2 i;

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

void plot_pixel(t_core *core, t_vec2 pos, int color)
{
	char *pixel;

	pixel = core->graphic.image.addr + (pos.y * core->graphic.image.line_size + pos.x * (core->graphic.image.bpp / 8));
	*(unsigned int *)pixel = color;
}
