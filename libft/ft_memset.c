/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:55:58 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/19 21:26:39 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*tmp_s;

	index = 0;
	tmp_s = (char *)b;
	while (index != len)
	{
		tmp_s[index] = (char)c;
		index++;
	}
	return (b);
}
