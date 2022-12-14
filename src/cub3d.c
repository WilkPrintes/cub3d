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

int	main(int argc, char **argv)
{
	int fd;

	if (argc < 2)
	{
		printf("Insira o mapa .cub\n");
		return (1); 
	}
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
	{
		printf("Insira um mapa .cub\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", get_next_line(fd));
}