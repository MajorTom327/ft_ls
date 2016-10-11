/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:14:48 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/25 17:11:04 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_parent;

	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp_parent = *alst;
		*alst = (*alst)->next;
		ft_memdel((void **)&tmp_parent);
	}
	del((void *)*alst, sizeof(*alst));
	*alst = NULL;
}
