/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:16:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/11 20:46:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>
#include <errno.h>
#include <stdio.h>

/*
** get_arg
** Get arg is the function who will transforme char arg in a int value.
*/

int			get_arg(char **arg, int ac)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 1;
	while (cnt < ac && arg[cnt][0] == '-')
	{
		i = get_flag(i, arg[cnt]);
		cnt++;
	}
	if (i != 0 || (i == 0 && cnt == 1))
		return (i);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putstr(&arg[--cnt][1]);
	ft_putstr("\nusage: ft_ls [-afFgGilmnOrRstu] [directory ...]\n");
	exit(0);
}

void		bsize(char *dir, t_dirent *f, int flag)
{
	t_stat	st;
	int		bs;
	char	*fp;

	if (!(flag & LS_FLAG_L))
		return ;
	bs = 0;
	while (f->d_name[0] != '\0')
	{
		if ((f->d_name[0] == '.' && flag & LS_FLAG_A) || f->d_name[0] != '.')
		{
			fp = ft_strdup(dir);
			fp = free_join(fp, "/");
			fp = free_join(fp, f->d_name);
			lstat(fp, &st);
			bs += st.st_blocks;
			free(fp);
		}
		f++;
	}
	ft_putstr("total ");
	ft_putnbr_endl(bs);
}

char		**get_dir(int ac, char **av, int *cnt)
{
	char	**dir;
	int		t;

	exit_mem((void *)(dir = ft_memalloc(sizeof(char *) * (size_t)(ac + 1))));
	t = 0;
	while (++t < ac)
	{
		if (av[t][0] == '-')
			continue ;
		t = 0;
		break ;
	}
	*cnt = t;
	if (ac == 1 || (t != 0 && t == ac))
	{
		dir[0] = ft_strdup("./");
		dir[1] = ft_strnew(0);
		return (dir);
	}
	dir[--ac] = ft_strnew(0);
	while (--ac >= 0)
		exit_mem((void *)(dir[ac] = ft_strdup(av[ac + 1])));
	t = 0;
	while (dir[t] && dir[t][0] == '-')
		t++;
	return (&dir[t]);
}

t_dirent	*get_files(char *dir_name)
{
	DIR			*directory;
	t_dirent	*files;
	t_dirent	*tmp;
	int			i;

	directory = opendir(dir_name);
	if (directory == NULL)
		return (exit_dir(dir_name));
	i = 0;
	while ((tmp = readdir(directory)) != NULL)
		i++;
	closedir(directory);
	directory = opendir(dir_name);
	exit_mem((void *)directory);
	exit_mem((files = ft_memalloc(sizeof(t_dirent) * (size_t)i)));
	while ((tmp = readdir(directory)) != NULL)
		ft_memcpy((void *)&files[--i], (void *)tmp, sizeof(t_dirent));
	closedir(directory);
	return (files);
}
