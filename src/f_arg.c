/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:39 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/08 11:24:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**f_args(int ac, char **av)
{
	char	**str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((str = (char **)ft_memalloc(ac)) == NULL)
		exit(EXIT_FAILURE);
	while (i < ac - 1)
	{
		if (av[i + 1][0] != '-')
			str[j++] = ft_strdup(av[i + 1]);
		i++;
	}
	return (str);
}

int	get_args(int ac, char **av)
{
	char	*arg;
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			if ((arg = ft_strdup(av[i])) == NULL)
				exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	if (arg != NULL)
	{
		i = (ft_strchr(arg, 'l') != NULL) ? i | 0x1 : i;
		i = (ft_strchr(arg, 'R') != NULL) ? i | 0x2 : i;
		i = (ft_strchr(arg, 'a') != NULL) ? i | 0x4 : i;
		i = (ft_strchr(arg, 'r') != NULL) ? i | 0x8 : i;
		i = (ft_strchr(arg, 't') != NULL) ? i | 0xF : i;
	}
	return (i);
}
