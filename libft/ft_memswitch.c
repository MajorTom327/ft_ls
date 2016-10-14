/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 20:49:29 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/14 03:55:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_memswitch(void *src, void *dst, size_t l)
{
	void *tmp;

	tmp = ft_memalloc(l);
	if (tmp == NULL)
		return ;
	ft_memcpy(tmp, src, l);
	ft_memcpy(src, dst, l);
	ft_memcpy(dst, tmp, l);
	ft_memdel(&tmp);
}
