/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:50:36 by vthomas           #+#    #+#             */
/*   Updated: 2015/11/25 19:51:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int const	init_start = start;
	char				*str_result;

	if (start > len)
		return (NULL);
	str_result = ft_strnew(len);
	if (str_result == NULL)
		return (NULL);
	start = 0;
	while (start < len)
	{
		str_result[start] = s[start + init_start];
		start++;
	}
	return (str_result);
}
