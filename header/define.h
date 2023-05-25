/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:40:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/25 16:28:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_vec2
{
	int x;
	int y;
}   t_vec2;

typedef struct s_player
{
	t_vec2 pos;
	double dir;
}   t_player;

typedef struct s_xpm
{
	void	*img;
	char	*relative_path;
	int		width;
	int		height;
}   t_xpm;

typedef struct s_texture_path
{
	char	*north_wall;
	char	*south_wall;
	char	*west_wall;
	char	*east_wall;
}	t_texture_path;

typedef struct s_graphic_config
{
	t_texture_path	textures;
	int				floor_rgb;
	int				ceiling_rgb;
}	t_graphic_config;

typedef struct s_map
{
	int			**matrix;
	int			lines;
	int			columns;
	t_player	player;
}	t_map;

typedef struct s_image {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_mlx_data {
	char	*win_name;
	void	*mlx;
	void	*win;
	t_image	image;
	int		is_valid;
}	t_mlx_data;

typedef struct s_core
{
	// void				*mlx;
	// void				*win;
	// void				*img;
	// char				*addr;
	t_mlx_data			graphic;
	// int					bits_per_pixel;
	// int					line_length;
	// int					endian;
	// int					width;
	// int					height;
	t_player 			player;
	t_graphic_config	config;
}   t_core;

#endif
