/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:54:59 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 22:06:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len1;
	size_t len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (size > len1 + 1)
	{
		while (i < size - len1 - 1)
		{
			dst[len1 + i] = src[i];
			i++;
		}
		dst[len1 + i] = '\0';
	}
	if (size >= len1)
		return (len1 + len2);
	return ((len1 + len2) - (len1 - size));
}
