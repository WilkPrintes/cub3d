/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:00:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/05/25 17:00:26 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "define.h"
#include "macro.h"
#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"
#include "map.h"
#include "map_setup.h"

int	get_key(int key, t_core *core)
{
	if (key == KEY_ESC)
	{
		mlx_loop_end(core->graphic.mlx);
		return (1);
	}
	if (key == KEY_D){
		printf("d\n");
		core->map.player.dir -= 0.05;
		raycasting(core, core->map.player);
	}
	if (key == KEY_W){
		printf("w\n");
		core->map.player.pos.x += 5 * cos(core->map.player.dir);
		core->map.player.pos.y -= 5 * sin(core->map.player.dir);
		raycasting(core, core->map.player);
	}
	if (key == KEY_A){
		core->map.player.dir += 0.05;
		raycasting(core, core->map.player);
		printf("a\n");
	}
	if (key == KEY_S)
	{
		printf("s\n");
		core->map.player.pos.x -= 5 * cos(core->map.player.dir);
		core->map.player.pos.y += 5 * sin(core->map.player.dir);
		raycasting(core, core->map.player);
	}
	return (0);
}

void load_textures(t_graphic_config *graphic, t_ray *ray, t_core *core)
{
	int i;

	i = 0;
	ray->n_texture.mlx_img = mlx_xpm_file_to_image(core->graphic.mlx, graphic->textures.north_wall, &i, &i);
	ray->n_texture.addr = mlx_get_data_addr(ray->n_texture.mlx_img, &ray->n_texture.bpp, &ray->n_texture.line_size, &ray->n_texture.endian);	
	ray->s_texture.mlx_img = mlx_xpm_file_to_image(core->graphic.mlx, graphic->textures.south_wall, &i, &i);
	ray->s_texture.addr = mlx_get_data_addr(ray->s_texture.mlx_img, &ray->s_texture.bpp, &ray->s_texture.line_size, &ray->s_texture.endian);
	ray->w_texture.mlx_img = mlx_xpm_file_to_image(core->graphic.mlx, graphic->textures.west_wall, &i, &i);
	ray->w_texture.addr = mlx_get_data_addr(ray->w_texture.mlx_img, &ray->w_texture.bpp, &ray->w_texture.line_size, &ray->w_texture.endian);
	ray->e_texture.mlx_img = mlx_xpm_file_to_image(core->graphic.mlx, graphic->textures.east_wall, &i, &i);
	ray->e_texture.addr = mlx_get_data_addr(ray->e_texture.mlx_img, &ray->e_texture.bpp, &ray->e_texture.line_size, &ray->e_texture.endian);
}

int main (int argc, char **argv)
{
	t_core		core;
	if (param_verifier(argc, argv[1]))
		return (1);
	if (!get_map(argv[1], &core.map, &core.config))
		return (EXIT_FAILURE);
	core.graphic = mount_mlx("prototype");
	core.map.player.dir = 60 * (PI / 180);
	load_textures(&core.config, &core.ray, &core);
	raycasting(&core, core.map.player);
	mlx_hook(core.graphic.win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
		&mouse_hook, &core.graphic);
	mlx_hook(core.graphic.win, 2, 1L<<0,  &get_key, &core);
	mlx_loop(core.graphic.mlx);
	free_texture_paths(&core.config.textures);
	ft_free_matrix((void *)&core.map.matrix, core.map.lines);
	return (dismount_mlx(&core.graphic));
}

void raycasting(t_core *core, t_player player){
	int		i;
	
	core->ray.angle = PI / 6 + player.dir;
	i = 0;
	while( i < WINDOW_WIDTH)
	{
		core->ray.dist_h = dist_horizontal(player, core->ray.angle, core);
		core->ray.dist_v = dist_vert(player, core->ray.angle, core);
		core->ray.distH = cos(player.dir - core->ray.angle) * sqrt(pow(core->ray.dist_h.x - player.pos.x, 2) + pow(core->ray.dist_h.y - player.pos.y, 2));
		core->ray.distV = cos(player.dir - core->ray.angle) * sqrt(pow(core->ray.dist_v.x - player.pos.x, 2) + pow(core->ray.dist_v.y - player.pos.y, 2));
		if (core->ray.distH < core->ray.distV)
		{
			core->ray.dist = wall_projection(core->ray.distH);
			if ( sin(core->ray.angle) < 0)
				create_wall(core, vec2(i, core->ray.dist), core->ray.dist, 'h' , core->ray.distH, core->ray.angle);
			else
				create_wall(core, vec2(i, core->ray.dist), core->ray.dist, 'h', core->ray.distH, core->ray.angle);
		}
		else
		{
			core->ray.dist =  wall_projection(core->ray.distV);
			if ( cos(core->ray.angle) < 0)
				create_wall(core, vec2(i, core->ray.dist), core->ray.dist, 'v', core->ray.distV, core->ray.angle);
			else
				create_wall(core, vec2(i, core->ray.dist), core->ray.dist, 'v', core->ray.distV, core->ray.angle);
		}
		core->ray.angle -=  (PI/3)/WINDOW_WIDTH;
		i++;
	}
	mlx_put_image_to_window(core->graphic.mlx, core->graphic.win, core->graphic.image.mlx_img, 0, 0);
}
