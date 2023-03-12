/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 18:49:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	generic_error(int exit_code, const char *locale,
	const char *description, char *usage)
{
	if (locale)
	{
		ft_putstr_fd((char *)(locale), 2);
		if (description)
			ft_putstr_fd(": ", 2);
		else
			ft_putstr_fd("\n", 2);
	}
	if (description)
	{
		ft_putstr_fd((char *)(description), 2);
		ft_putstr_fd("\n", 2);
	}
	if (usage)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd((char *)(usage), 2);
		ft_putstr_fd("\n", 2);
	}
	return (exit_code);
}

t_mlx_data	mlx_error(t_mlx_data *data, const char *err_location,
		const char *description)
{
	generic_error(EXIT_FAILURE, err_location, description, NULL);
	data->is_valid = 0;
	return (*data);
}
