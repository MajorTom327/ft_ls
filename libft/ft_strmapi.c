/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:56:10 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 18:11:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	index;

	if (s != NULL || f != NULL)
	{
		index = 0;
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (NULL);
		while (index != ft_strlen(s))
		{
			str[index] = f(index, s[index]);
			index++;
		}
		return (str);
	}
	return (0);
}
