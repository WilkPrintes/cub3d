/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:31:32 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdlib.h>
# include "macro.h"
# include "define.h"

int		rerender_image(t_mlx_data *data);
void	paint_rectangle(t_image *image,
			t_pixel start_corner, t_pixel end_corner, int color);

#endif
