/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/04/07 15:48:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)(s1);
	cast_s2 = (unsigned char *)(s2);
	i = 0;
	while (*(cast_s1 + i) == *(cast_s2 + i) && *(cast_s1 + i))
		i++;
	return (*(cast_s1 + i) - *(cast_s2 + i));
}
