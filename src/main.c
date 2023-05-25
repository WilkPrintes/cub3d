#include "raycasting.h"
#include "define.h"
#include "macro.h"
#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"
#include "map.h"
#include "map_setup.h"

t_map				map;
// int map[10][10] = {
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 		{1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
// 		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 0, 2, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// 		{1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// 	};

// int close_win(t_core *core)
// {
// 	mlx_destroy_window(core->mlx, core->win);
// 	exit(0);
// }

int	get_key(int key, t_core *core)
{
	if (key == KEY_ESC)
	{
		mlx_loop_end(core->graphic.mlx);
		return (1);
	}
	if (key == KEY_D){
		printf("d\n");
		core->player.dir -= 0.05;
		raycasting(core, core->player, map);
	}
	if (key == KEY_W){
		printf("w\n");
		core->player.pos.x += 5 * cos(core->player.dir);
		core->player.pos.y -= 5 * sin(core->player.dir);
		raycasting(core, core->player, map);
	}
	if (key == KEY_A){
		core->player.dir += 0.05;
		raycasting(core, core->player, map);
		printf("a\n");
	}
	if (key == KEY_S)
	{
		printf("s\n");
		core->player.pos.x -= 5 * cos(core->player.dir);
		core->player.pos.y += 5 * sin(core->player.dir);
		raycasting(core, core->player, map);
	}
	return (0);////
}

int main (int argc, char **argv)
{
	// void		*mlx;
	// void		*win;
	// void		*frame;
	// float		angle;
	int			i;
	t_core		core;
	// t_player	player;
	// t_xpm		xpmTest;

	t_graphic_config	config;
	// t_map				map;

	if (param_verifier(argc, argv[1]))
		return (1);
	if (!get_map(argv[1], &map, &config))
		return (EXIT_FAILURE);
	i = 0;
	// core.mlx = mlx_init();
	// core.win = mlx_new_window(core.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
	// core.img = mlx_new_image(core.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// core.addr = mlx_get_data_addr(core.img, &core.bits_per_pixel, &core.line_length, &core.endian);
	core.graphic = mount_mlx("prototype");
	// player.pos = show_minimap(&core, map.matrix);
	// player.pos = show_minimap(&core, map);
	map.player.dir = 60 * (PI / 180);
	core.player = map.player;
	// raycasting(&core, player, map.matrix);
	raycasting(&core, core.player, map);
	// mlx_hook(core.win, 17, 0, close_win, &core);
	// mlx_hook(core.graphic.win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK,
	// 	&key_press_hook, &core.graphic);
	mlx_hook(core.graphic.win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
		&mouse_hook, &core.graphic);
	mlx_hook(core.graphic.win, 2, 1L<<0,  &get_key, &core);
	mlx_loop(core.graphic.mlx);

	free_texture_paths(&config.textures);
	ft_free_matrix((void *)&map.matrix, map.lines);
	return (dismount_mlx(&core.graphic));
}

// void raycasting(t_core *core, t_player player, int map[10][10]){
void raycasting(t_core *core, t_player player, t_map map){
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
		dist_h = dist_horizontal(map.matrix, player, angle, core);
		dist_v = dist_vert(map.matrix, player, angle, core);
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
