/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/03 08:59:54 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

t_file	*f_get_file(char **dir, int size)
{
	int	i;
	int	c;
	DIR	*di;
	t_file	*file;

	if ((file = (t_file *)ft_memalloc(sizeof(t_file) * size)) == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	dbg_var_int("f_get_file", "size", size, 2);
	while (i < size)
	{
		dbg_var_int("f_get_file", "i", i, 2);
		dbg_var_str("f_get_file","dir[i]", dir[i], 2);
		if ((di = opendir(dir[i])) == NULL)
			perror(NULL);
		c = 0;
		while (readdir(di))
			c++;
		closedir(di);
		if ((di = opendir(dir[i])) == NULL)
			perror(NULL);
		file[i].f_list = (dirent **)ft_memalloc(sizeof(dirent) * c);
		file[i].nb = c;
		file[i].name = ft_strdup(dir[i]);
		c = 0;
		while ((file[i].f_list[c] = readdir(di)))
			c++;
		i++;
	}
	dbg_info("f_get_file", "end of function", 2);
	return (file);
}

void	f_ls(char **dir, int size, int arg)
{
	t_file	*f_list = f_get_file(dir, size);
	print_file(f_list, size, arg);
//	int i = 0;
//	while (i != f_list[0].nb)
//	{
//		ft_putendl(f_list[0].f_list[i]->d_name);
//		i++;
//	}
}
