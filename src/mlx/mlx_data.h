/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:59:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 21:14:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DATA_H
# define MLX_DATA_H

# include <stdlib.h>
# include <mlx.h>
# include "macro.h"
# include "define.h"
# include "error.h"

t_mlx_data	mount_mlx(char *window_name);
int			dismount_mlx(t_mlx_data *data);

#endif
