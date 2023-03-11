/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:24:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/27 00:59:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*s2;

	if (!s1)
		return (NULL);
	if (ft_strlen(set) == 0)
	{
		s2 = ft_strdup(s1);
		return (s2);
	}
	start = (char *)(s1);
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (ft_strchr(set, *start) != NULL && *start != '\0')
		start++;
	while (ft_strchr(set, *end) != NULL && end > start)
		end--;
	s2 = ft_substr(start, 0, end - start + 1);
	return (s2);
}
