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

int main (int argc, char **argv)
{
	int			i;
	t_core		core;

	if (param_verifier(argc, argv[1]))
		return (1);
	if (!get_map(argv[1], &core.map, &core.config))
		return (EXIT_FAILURE);
	i = 0;
	core.graphic = mount_mlx("prototype");
	core.map.player.dir = 60 * (PI / 180);
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
	t_vec2	dist_h;
	t_vec2	dist_v;
	double	distH;
	double	distV;
	double	dist;
	float	angle;
	int		i;

	angle = PI / 6 + player.dir;
	i = 0;
	while( i < WINDOW_WIDTH)
	{
		dist_h = dist_horizontal(player, angle, core);
		dist_v = dist_vert(player, angle, core);
		distH = cos(player.dir - angle) * sqrt(pow(dist_h.x - player.pos.x, 2) + pow(dist_h.y - player.pos.y, 2));
		distV = cos(player.dir - angle) * sqrt(pow(dist_v.x - player.pos.x, 2) + pow(dist_v.y - player.pos.y, 2));
		if (distH < distV)
		{
			dist = wall_projection(distH);
			if ( sin(angle) < 0)
				create_wall(core, vec2(i, dist), dist, 0xFF6600);
			else
				create_wall(core, vec2(i, dist), dist, 0xFF0000);
		}
		else{
			dist =  wall_projection(distV);
			if ( cos(angle) < 0)
				create_wall(core, vec2(i, dist), dist, 0x66FFFF);
			else
				create_wall(core, vec2(i, dist), dist, 0x00FF00);
		}
		angle -=  (PI/3)/WINDOW_WIDTH;
		i++;
	}
	mlx_put_image_to_window(core->graphic.mlx, core->graphic.win, core->graphic.image.mlx_img, 0, 0);
}
