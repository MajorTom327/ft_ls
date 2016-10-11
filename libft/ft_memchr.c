/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:27:36 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 21:30:50 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (tmp_s[index] == (unsigned char)c)
			return (tmp_s + index);
		index++;
	}
	return (0);
}
