#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "define.h"
#include "verifier.h"
#include "mlx_data.h"
#include "mlx_hook.h"
#include "render.h"
#include "map.h"
#define PI 3.14159265359
#define WIDTH 640
#define HEIGHT 400
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_W 119
#define KEY_ESC 65307

void    plot_pixel(t_core *core, t_vec2 pos, int color);
void    print_sky_and_floor(t_core *core);
void    create_rectangle(t_core *core, t_vec2 pos, t_vec2 size, int color);
// t_vec2  show_minimap(t_core *core, int map[10][10]);
t_vec2  show_minimap(t_core *core, t_map map);
void    print_player(t_core *core, t_player player);
// void    show_dir(t_core *core, t_player player, int map[10][10]);
void    show_dir(t_core *core, t_player player, int **map);
// t_vec2  dist_horizontal(int map[10][10], t_player player, double angle, t_core *core);
t_vec2  dist_horizontal(int **map, t_player player, double angle, t_core *core);
// t_vec2  dist_vert(int map[10][10], t_player player, double angle, t_core *core);
t_vec2  dist_vert(int **map, t_player player, double angle, t_core *core);
t_vec2  vec2(int x, int y);
// int     is_wall(double ay, double ax, int map[10][10]);
int     is_wall(double ay, double ax, int **map);
double  wall_projection(double dist_wall);
void    create_wall(t_core *core, t_vec2 pos, double wall_height, int color);
// void    raycasting(t_core *core, t_player player, int map[10][10]);
void    raycasting(t_core *core, t_player player, int **map);