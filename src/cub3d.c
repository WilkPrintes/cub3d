/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:02:02 by wprintes          #+#    #+#             */
/*   Updated: 2022/11/16 19:02:02 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void create_square(t_data *data, int increment_x, int increment_y);
void render_map(int **map, t_data data);
void square(t_data data, int x, int y, int color);
void init_map(int map[10][10], t_data *data);
void free_map(int **map);

int	get_key(int key, t_data *data){
	printf("key: %d\n", key);
	if (key == 65307)
	{
		free_map(data->map);
		exit(0);
	}
	if (key == 119)
		create_square(data, 0, -10);
	if (key == 115)
		create_square(data, 0, 10);
	if (key == 97)
		create_square(data, -10, 0);
	if (key == 100)
		create_square(data, 10, 0);
	return (0);
}

void free_map(int **map)
{
	int i;

	i = 0;
	while (i < 10)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{
	t_data data;

	int map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	data.map = (int **)malloc(sizeof(int *) * 10);
	init_map(map, &data);
	data.player_x = 64*10/2;
	data.player_y = 64*10/2;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, 64*10, 64*10, "cub3d");
	create_square(&data, 0, 0);
	mlx_key_hook(data.win, &get_key, &data);
	mlx_loop(data.ptr);
}

void init_map(int map[10][10], t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 10)
	{
		data->map[y] = (int *)malloc(sizeof(int) * 10);
		while (x < 10)
		{
			data->map[y][x] = map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

void render_map(int **map, t_data data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 10)
	{
		while (x < 10)
		{
			if (map[y][x] == 1)
				square(data, x * 64, y * 64, 0x00FF00);
			else
				square(data, x * 64, y * 64, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
}

void square(t_data data, int x, int y, int color)
{
	int x_aux;
	int y_aux;

	x_aux = x;
	y_aux = y;
	while (x < x_aux + 63)
	{
		mlx_pixel_put(data.ptr, data.win, x, y, color);
		x++;
		if (x == x_aux + 63)
		{
			x = x_aux;
			y++;
		}
		if (y == y_aux + 63)
			break;
	}
}

void create_square(t_data *data, int increment_x, int increment_y)
{
	int x_aux;
	int y_aux;

	mlx_clear_window(data->ptr, data->win);
	render_map(data->map, *data);
	x_aux = data->player_x;
	y_aux = data->player_y;
	data->player_x = x_aux + increment_x;
	data->player_y = y_aux + increment_y;
	while (data->player_x < x_aux + 20 + (increment_x))
	{
		mlx_pixel_put(data->ptr, data->win, data->player_x, data->player_y, 0xFF0000);
		data->player_x++;
		if (data->player_x == x_aux + 20 + (increment_x))
		{
			data->player_x = x_aux + increment_x;
			data->player_y++;
		}
		if (data->player_y == y_aux + 20 + (increment_y))
			break;
	}
	data->player_x = x_aux + increment_x;
	data->player_y = y_aux + increment_y;
}
*/
