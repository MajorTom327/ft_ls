/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 07:49:38 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/18 19:32:03 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *sf_getcolor(t_dirent file)
{
	const int type = file.d_type;

	if (type == DT_FIFO)
		return ("\033[32m");
	if (type == DT_CHR)
		return ("\033[33m");
	if (type == DT_DIR)
		return ("\033[34m");
	if (type == DT_BLK)
		return ("\033[35m");
	if (type == DT_REG)
		return ("\033[36m");
	if (type == DT_LNK)
		return ("\033[37m");
	if (type == DT_SOCK)
		return ("\033[38m");
	if (type == DT_WHT)
		return ("\033[39m");
	if (type == DT_UNKNOWN)
			return ("\033[0m");
	return ("\033[90m");
}

static void sf_print(t_dirent f, int arg)
{
	char *str;

	if (f.d_name[0] == '.' && !(arg & 0x04))
		return ;
	str = ft_strnew(255);
	if (str == NULL)
		return ;
	if (arg & 0x10)
		ft_strcat(str, sf_getcolor(f));
	ft_strcat(str, f.d_name);
	if (arg & 0x10)
		ft_strcat(str, "\033[0m");
	ft_putstr(str);
	ft_putstr("\t\t");
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
			sf_print(*f_list[j].f_list[i], arg);
			//ft_putstr(f_list[j].f_list[i]->d_name);
			if (!((i + 1) % 5))
				ft_putendl("");
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}
