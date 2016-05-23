/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/08 12:45:47 by vthomas          ###   ########.fr       */
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
	while (i < size)
	{
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
		c = 0;
		while (file[i].f_list[c] = readdir(di))
			c++;
		i++;
	}
	return (file);
}

void	f_ls(char **dir, int size, int arg)
{
	t_file	*f_list = f_get_file(dir, size);
	int i = 0;
	while (i != f_list[0].nb)
	{
		ft_putstr(f_list[0].f_list[i]->d_name);
		ft_putstr("\t");
		i++;
	}
}
