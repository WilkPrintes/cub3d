/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:38:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/15 23:09:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// Screen size
# define WINDOW_WIDTH	1080
# define WINDOW_HEIGHT	720

// Map identifiers:
// Wall textures
# define NORTH_WALL_TEXTURE_ID	"NO"
# define SOUTH_WALL_TEXTURE_ID	"SO"
# define EAST_WALL_TEXTURE_ID	"EA"
# define WEST_WALL_TEXTURE_ID	"WE"

// Colors
# define FLOOR_COLOR_ID		"F"
# define CEILING_COLOR_ID	"C"

// Scene
# define EMPTY_SPACE	"0"
# define WALL			"1"
# define SPAWN_NORTH	"N"
# define SPAWN_SOUTH	"S"
# define SPAWN_WEST		"W"
# define SPAWN_EAST		"E"

// X11 used event codes and their masks
# define X_KEY_PRESS_EVENT	02
# define X_KEY_PRESS_MASK	1L

# define X_DESTROY_NOTIFY_EVENT	17
# define X_DESTROY_NOTIFY_MASK	131072

// Keypress values
# define LEFT_ARROW_KEY		65361
# define RIGHT_ARROW_KEY	65363

# define KEY_ESC	65307

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
