/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:59:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:02:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_H
# define MLX_HOOK_H

# include <stdlib.h>
# include "macro.h"
# include "define.h"

int	mouse_hook(t_mlx_data *data);
int	key_press_hook(int keycode, t_mlx_data *data);

#endif
