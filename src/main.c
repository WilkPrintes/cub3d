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

static void	load_textures(t_graphic_config *graphic, t_ray *ray, t_core *core);
static void	free_texture_images(t_core core);

int	main(int argc, char **argv)
{
	t_core		core;

	if (param_verifier(argc, argv[1]))
		return (1);
	if (!get_map(argv[1], &core.map, &core.config))
		return (EXIT_FAILURE);
	core.graphic = mount_mlx("cub3D");
	load_textures(&core.config, &core.ray, &core);
	raycasting(&core, core.map.player);
	mlx_hook(core.graphic.win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
		&mouse_hook, &core.graphic);
	mlx_hook(core.graphic.win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK,
		&keypress_hook, &core);
	mlx_loop(core.graphic.mlx);
	mlx_expose_hook(core.graphic.win, &rerender_image, &core.graphic);
	free_texture_paths(&core.config.textures);
	free_texture_images(core);
	ft_free_matrix((void *)&core.map.matrix, core.map.lines);
	return (dismount_mlx(&core.graphic));
}

static void	free_texture_images(t_core core)
{
	mlx_destroy_image(core.graphic.mlx, core.ray.n_texture.mlx_img);
	mlx_destroy_image(core.graphic.mlx, core.ray.s_texture.mlx_img);
	mlx_destroy_image(core.graphic.mlx, core.ray.e_texture.mlx_img);
	mlx_destroy_image(core.graphic.mlx, core.ray.w_texture.mlx_img);
}

static void	load_textures(t_graphic_config *graphic, t_ray *ray, t_core *core)
{
	int	i;

	i = 0;
	ray->n_texture.mlx_img = mlx_xpm_file_to_image(
			core->graphic.mlx, graphic->textures.north_wall, &i, &i);
	ray->n_texture.addr = mlx_get_data_addr(
			ray->n_texture.mlx_img, &ray->n_texture.bpp,
			&ray->n_texture.line_size, &ray->n_texture.endian);
	ray->s_texture.mlx_img = mlx_xpm_file_to_image(
			core->graphic.mlx, graphic->textures.south_wall, &i, &i);
	ray->s_texture.addr = mlx_get_data_addr(
			ray->s_texture.mlx_img, &ray->s_texture.bpp,
			&ray->s_texture.line_size, &ray->s_texture.endian);
	ray->w_texture.mlx_img = mlx_xpm_file_to_image(
			core->graphic.mlx, graphic->textures.west_wall, &i, &i);
	ray->w_texture.addr = mlx_get_data_addr(
			ray->w_texture.mlx_img, &ray->w_texture.bpp,
			&ray->w_texture.line_size, &ray->w_texture.endian);
	ray->e_texture.mlx_img = mlx_xpm_file_to_image(
			core->graphic.mlx, graphic->textures.east_wall, &i, &i);
	ray->e_texture.addr = mlx_get_data_addr(
			ray->e_texture.mlx_img, &ray->e_texture.bpp,
			&ray->e_texture.line_size, &ray->e_texture.endian);
}
