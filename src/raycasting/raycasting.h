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


void    plot_pixel(t_core *core, t_vec2 pos, int color);
void    print_sky_and_floor(t_core *core);
void    create_rectangle(t_core *core, t_vec2 pos, t_vec2 size, int color);
t_vec2  show_minimap(t_core *core, t_map map);
void    print_player(t_core *core, t_player player);
void    show_dir(t_core *core, t_player player, int **map);
t_vec2  dist_horizontal(t_player player, double angle, t_core *core);
t_vec2  dist_vert(t_player player, double angle, t_core *core);
t_vec2  vec2(int x, int y);
int     is_wall(double ay, double ax, t_map map);
double  wall_projection(double dist_wall);
void    create_wall(t_core *core, t_vec2 pos, double wall_height, int color, double dist_wall, double angle);
void    raycasting(t_core *core, t_player player);
