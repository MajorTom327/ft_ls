/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 07:49:38 by vthomas           #+#    #+#             */
/*   Updated: 2016/07/10 04:46:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <debug.h>

static char *sf_getcolor(const char *file)
{
	//const int type = file.d_type;
	struct stat *buf;
	int type;

	buf = NULL;
	lstat(file, &buf);
	if (buf == NULL)
		exit(EXIT_FAILURE);
	type = buf->st_mode;
	dbg_info("sf_getcolor", "In the function", 3);
	dbg_var_int("sf_getcolor","FILE VALUE", type, 3);
//	if (type == S_IFMT)
//		return ("\033[31m");
	if (type == S_IFDIR)
		return ("\033[34m");
	if (type == S_IFBLK)
		return ("\033[35m");
	if (type == S_IFREG)
		return ("\033[36m");
	if (type == S_IFLNK)
		return ("\033[37m");
	if (type == S_IFSOCK)
		return ("\033[38m");
	if (type == S_IFWHT)
		return ("\033[39m");
	return ("\033[90m");
}

static void sf_print(t_dirent f, int arg, const char *dir)
{
	char *str;

	if (f.d_name[0] == '.' && !(arg & 0x04))
		return ;
	str = ft_strnew(255);
	if (str == NULL)
		return ;
	if (arg & 0x10)
		ft_strcat(str, sf_getcolor(dir));
	ft_strcat(str, f.d_name);
	if (arg & 0x10)
		ft_strcat(str, "\033[0m");
//	ft_putstr(str);
//	ft_putstr("\t\t");
	ft_putendl(str);//TODO: ENDL AUTO
	ft_strdel(&str);
}

void	print_file(t_file *f_list, int size, int arg)
{
	int i;
	int j;

	j = 0;
	size--;
	while (j < size)
	{
		i = 0;
		if (size > 1)
		{
			if (j)
				write(1, "\n\n", 2);
			ft_putstr(f_list[j].name);
			write(1, ":\n", 2);
		}
		while (i < f_list[j].nb)
		{
			sf_print(*f_list[j].f_list[i], arg, f_list[j].name);
			//ft_putstr(f_list[j].f_list[i]->d_name);
			if (!((i + 1) % 5))
				ft_putendl("");
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}
