/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 16:26:16 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 19:22:28 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_search(const char *s1, const char *s2, int i_s1)
{
	int	i_s2;

	i_s2 = 0;
	while (s2[i_s2] == s1[i_s1] && s1[i_s1] != '\0' && s2[i_s2] != '\0')
	{
		i_s1++;
		i_s2++;
		if (s2[i_s2] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			if (f_search(s1, s2, i) == 1)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
