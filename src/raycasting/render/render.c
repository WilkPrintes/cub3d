/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:23:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 16:27:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	rerender_image(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img, 0, 0);
	return (0);
}
