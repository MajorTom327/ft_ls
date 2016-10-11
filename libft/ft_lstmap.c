/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:16:43 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/25 17:28:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *to_return;

	result = f(lst);
	to_return = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		result->next = f(lst);
		result = result->next;
	}
	return (to_return);
}
