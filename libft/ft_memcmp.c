/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 04:23:07 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/23 20:44:55 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_cpy = (const unsigned char *)s1;
	const unsigned char	*s2_cpy = (const unsigned char *)s2;

	i = 0;
	if (n == 0)
		return (0);
	while (s1_cpy[i] == s2_cpy[i] && n > i)
	{
		if (i == (n - 1))
			return (0);
		i++;
	}
	return ((int)(s1_cpy[i] - s2_cpy[i]));
}
