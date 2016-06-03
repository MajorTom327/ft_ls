/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:39 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/03 08:02:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

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
	dbg_info("get_args", "Beggining of the function", 2);
	while (i < ac)
	{
		dbg_var_int("get_args","Argument number", i, 3);
		if (av[i][0] == '-')
			if ((arg = ft_strdup(av[i])) == NULL)
				exit(EXIT_FAILURE);
		i++;
	}
	dbg_info("get_args", "First While passed !", 2);
	i = 0;
	if (arg != NULL && av[1][0] == '-')
	{
		dbg_info("get_args", "sorting the data...", 2);
		i = (ft_strchr(arg, 'l') != NULL) ? i | 0x1 : i;
		i = (ft_strchr(arg, 'R') != NULL) ? i | 0x2 : i;
		i = (ft_strchr(arg, 'a') != NULL) ? i | 0x4 : i;
		i = (ft_strchr(arg, 'r') != NULL) ? i | 0x8 : i;
		i = (ft_strchr(arg, 't') != NULL) ? i | 0xF : i;
	}
	dbg_info("get_args", "Done !", 2);
	dbg_var_int("get_args","Argument value:", i, 2);
	return (i);
}
