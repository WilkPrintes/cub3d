/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 16:58:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdlib.h>
# include "macro.h"
# include "define.h"

int		rerender_image(t_mlx_data *data);

// render_utils.c
void	plot_pixel(t_core *core, t_vec2 pos, int color);
int		ft_mlx_pixel_get(t_image *img, int x, int y);
t_vec2	vec2(int x, int y);

#endif
