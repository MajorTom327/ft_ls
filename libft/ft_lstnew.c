/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:18:44 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/22 20:24:47 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*val;

	val = ft_memalloc(sizeof(val));
	if (val == NULL)
		return (NULL);
	if (content == NULL)
	{
		val->content = NULL;
		val->content_size = 0;
		return (val);
	}
	val->content = ft_memalloc(content_size);
	if (val->content == NULL)
		return (NULL);
	ft_memcpy(val->content, content, content_size);
	return (val);
}
