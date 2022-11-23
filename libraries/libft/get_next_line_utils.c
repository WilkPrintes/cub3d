/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:04:17 by wprintes          #+#    #+#             */
/*   Updated: 2022/11/23 10:40:55 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_n(char *buffer)
{
	size_t	counter;

	counter = 0;
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	return (counter);
}
