/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:59:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/28 16:35:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_H
# define MLX_HOOK_H

# include <stdlib.h>
# include "macro.h"
# include "define.h"
# include "raycasting.h"

int	mouse_hook(t_mlx_data *data);
int	keypress_hook(int key, t_core *core);

#endif
