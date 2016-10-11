/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:39:58 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/15 10:57:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t t)
{
	char *str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * t + 1);
	if (str == NULL)
		return (NULL);
	str[t] = '\0';
	ft_strclr(str);
	return (str);
}
