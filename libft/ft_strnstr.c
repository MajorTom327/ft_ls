/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:35:46 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/23 21:20:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_search(const char *s1, const char *s2, size_t i_s1, size_t len)
{
	size_t	i_s2;

	i_s2 = 0;
	while (s2[i_s2] == s1[i_s1] && s1[i_s1] != '\0' && s2[i_s2] != '\0' &&
			i_s1 < len)
	{
		i_s1++;
		i_s2++;
		if (i_s2 == ft_strlen(s2) && i_s2 <= ft_strlen(s2))
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			if (f_search(s1, s2, i, len) == 1)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
