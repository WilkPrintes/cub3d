/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:01:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 18:00:54 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int is_wall(double ay, double ax, t_map map)
{
	if (ay / 64 < 0 || ax / 64 < 0 || ay / 64 >= map.lines || ax / 64 >= map.columns)
		return (-1);
	if (map.matrix[(int)ay / 64][(int)ax / 64] == 1)
		return (1);
	return (0);
}
