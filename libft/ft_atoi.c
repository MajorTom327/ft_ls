/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 04:07:31 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/23 21:24:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_value(const char *str)
{
	size_t	index;
	int		myvalue;

	index = 0;
	myvalue = 0;
	while (index <= ft_strlen(str) && ft_isdigit((int)str[index]) == 0)
		index++;
	if (index == ft_strlen(str))
		return (-1);
	while (index != ft_strlen(str) && ft_isdigit((int)str[index]) == 1)
	{
		myvalue = myvalue * 10 + ((int)str[index] - '0');
		index++;
	}
	return (myvalue);
}

static int	get_sign(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
		return (-1);
	else if (str[i] == '+' && ft_isdigit(str[i + 1]) == 1)
		return (1);
	else if (ft_isdigit(str[i]) == 1)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	value;

	value = get_value(str);
	value *= get_sign(str);
	return (value);
}
