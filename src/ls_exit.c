/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:16:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/11 11:16:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <stdio.h>
#include <errno.h>

void	exit_failure(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	exit_mem(void *mem)
{
	if (mem == NULL)
		exit_failure();
}
