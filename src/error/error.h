/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:24:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 20:38:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "define.h"
# include "libft.h"

int			generic_error(int exit_code, const char *locale,
				const char *description, char *usage);
t_mlx_data	mlx_error(t_mlx_data *data, const char *err_location,
				const char *description);

#endif
