/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:25 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 19:32:01 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	index = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (index != n)
	{
		dst_tmp[index] = src_tmp[index];
		if (dst_tmp[index] == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
