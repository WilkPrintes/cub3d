/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:05:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/03/11 19:05:22 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFIER_H
# define VERIFIER_H

# include <stdlib.h>
# include "define.h"

int	fd_verifier(int fd);
int	data_verifier(t_mlx_data *data);
int	param_verifier(const int argc, const char *map_file);

#endif
