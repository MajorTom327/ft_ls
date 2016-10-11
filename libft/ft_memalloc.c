/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:38:25 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/01 04:00:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t t)
{
	void	*memory;
	char	*tmp_mem;
	size_t	i;

	memory = NULL;
	i = 0;
	memory = malloc(t);
	if (memory == NULL)
		return (NULL);
	tmp_mem = (char *)memory;
	while (i <= t)
	{
		tmp_mem[i] = 0;
		i++;
	}
	return (memory);
}
