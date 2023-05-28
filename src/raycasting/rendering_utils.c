/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:34:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 01:23:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void plot_pixel(t_core *core, t_vec2 pos, int color)
{
	char *pixel;

	pixel = core->graphic.image.addr + (pos.y * core->graphic.image.line_size + pos.x * (core->graphic.image.bpp / 8));
	*(unsigned int *)pixel = color;
}
