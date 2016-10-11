/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 05:56:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 06:16:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debug_title(char *text)
{
	if (text == NULL)
		return ;
	ft_putstr("\t\e[34m[ ");
	ft_putstr(text);
	ft_putendl(" ]\e[0m");
}

void	ft_debug_info(char *function, char *text)
{
	if (text == NULL || function == NULL)
		return ;
	ft_putstr("\e[33m(");
	ft_putstr(function);
	ft_putstr(")\t\e[32m");
	ft_putstr(text);
	ft_putendl("\e[0m");
}

void	ft_debug_bloc(char *function, char *text)
{
	if (text == NULL || function == NULL)
		return ;
	ft_putstr("\e[33m(");
	ft_putstr(function);
	ft_putstr(")\t\e[90m<");
	ft_putstr(text);
	ft_putendl(">\e[0m");
}

void	ft_debug_var_int(char *function, char *text, int value)
{
	if (text == NULL || function == NULL)
		return ;
	ft_putstr("\e[33m(");
	ft_putstr(function);
	ft_putstr(")\t\e[32m");
	ft_putstr(text);
	ft_putstr(":\t\e[35m");
	ft_putnbr(value);
	ft_putendl("\e[0m");
}

void	ft_debug_var_char(char *function, char *text, char *value)
{
	if (text == NULL || function == NULL)
		return ;
	ft_putstr("\e[33m(");
	ft_putstr(function);
	ft_putstr(")\t\e[32m");
	ft_putstr(text);
	ft_putstr(":\t\e[35m");
	if (value != NULL)
		ft_putstr(value);
	else
		ft_putstr("NULL");
	ft_putendl("\e[0m");
}
