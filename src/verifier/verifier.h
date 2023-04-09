/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:05:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/04/07 14:42:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFIER_H
# define VERIFIER_H

# include <stdlib.h>
# include <fcntl.h>
# include "define.h"

int	fd_verifier(int fd);
int	file_access_verifier(char *filename);
int	data_verifier(t_mlx_data *data);
int	param_verifier(const int argc, const char *map_file);

#endif
