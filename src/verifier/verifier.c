/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:33:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/15 23:22:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verifier.h"

static int	is_valid_file_extension(const char *file, const char *ext);

int	file_access_verifier(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (1);
	}
	close(fd);
	return (0);
}

int	fd_verifier(int fd)
{
	if (fd >= 0)
		return (0);
	return (generic_error(EXIT_FAILURE, "open", "Failed to open file.", NULL));
}

int	data_verifier(t_mlx_data *data)
{
	if (data->is_valid == 1)
		return (0);
	dismount_mlx(data);
	return (1);
}

int	param_verifier(const int argc, const char *map_file)
{
	char	*correct_usage;

	correct_usage = "./cub3D map_name.cub";
	if (argc < 2)
		return (generic_error(EXIT_FAILURE, "cub3D",
				"Too few arguments.", correct_usage));
	if (argc > 2)
		return (generic_error(EXIT_FAILURE, "cub3D",
				"Too many arguments.", correct_usage));
	if (!is_valid_file_extension(map_file, ".cub"))
		return (generic_error(EXIT_FAILURE, "cub3D",
				"Invalid file name or extension.", correct_usage));
	return (0);
}

static int	is_valid_file_extension(const char *file, const char *ext)
{
	size_t	ext_len;
	size_t	file_len;

	if (!file || !ext)
		return (0);
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (file_len <= ext_len)
		return (0);
	if (ft_strncmp(file + file_len - ext_len, ext, ext_len) != 0)
		return (0);
	return (1);
}
