/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:38:30 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/15 11:30:32 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	index;
	char	*result;

	result = ft_strnew(ft_strlen(s));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index != ft_strlen(s))
	{
		result[index] = s[index];
		index++;
	}
	return (result);
}
