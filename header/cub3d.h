/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:21:26 by wprintes          #+#    #+#             */
/*   Updated: 2022/11/23 10:21:26 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>

# define X 1280
# define Y 720

typedef struct s_data
{
	void	*ptr;
	void	*win;
	int		player_x;
	int		player_y;
	int		**map;
}	t_data;

#endif
