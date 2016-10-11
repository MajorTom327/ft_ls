/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:51:28 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/25 16:07:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *a, char const *b)
{
	int		i;
	int		j;
	char	*r;

	if (!a || !b)
		return (NULL);
	i = 0;
	j = 0;
	if (!(r = (char*)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	while (a[i] != '\0')
	{
		r[j] = a[i];
		i++;
		j++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		r[j] = b[i];
		i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}
