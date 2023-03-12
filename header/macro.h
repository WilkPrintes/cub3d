/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:38:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:17:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// Screen size
# define WINDOW_WIDTH	1080
# define WINDOW_HEIGHT	720

// X11 used event codes and their masks
# define X_KEY_PRESS_EVENT	02
# define X_KEY_PRESS_MASK	1L

# define X_DESTROY_NOTIFY_EVENT	17
# define X_DESTROY_NOTIFY_MASK	131072

// Keypress values
# define LEFT_ARROW_KEY		65361
# define RIGHT_ARROW_KEY	65363

# define KEY_ESC			65307

# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

// Error codes (values used as defined in <errno.h>)
# ifndef EBADF
#  define EBADF		9
# endif
# ifndef EINVAL
#  define EINVAL	22
# endif
# ifndef ECANCELED
#  define ECANCELED	125
# endif

#endif
