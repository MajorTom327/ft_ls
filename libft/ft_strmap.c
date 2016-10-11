/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:53:59 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/20 17:51:18 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	index;

	if (s != NULL && f != NULL)
	{
		index = 0;
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (NULL);
		while (index != ft_strlen(s))
		{
			str[index] = f(s[index]);
			index++;
		}
		return (str);
	}
	return (0);
}
