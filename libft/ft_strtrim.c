/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:52:55 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 17:56:42 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == '\t' || s[start] == ' ' || s[start] == '\n'))
	{
		if (start == end)
			return ((char *)&(ft_strdup(s)[end + 1]));
		start++;
	}
	while ((s[end] == '\t' || s[end] == ' ' || s[end] == '\n') && end != 0)
		end--;
	len = end - start + 1;
	result = ft_strsub(s, (unsigned int)start, len);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	return (result);
}
