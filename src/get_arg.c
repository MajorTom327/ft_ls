/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:16:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/11 12:30:34 by vthomas          ###   ########.fr       */
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
		i = (ft_strchr(arg[cnt], 'l') != NULL) ? i | LS_FLAG_L : i;
		i = (ft_strchr(arg[cnt], 'R') != NULL) ? i | LS_FLAG_R : i;
		i = (ft_strchr(arg[cnt], 'a') != NULL) ? i | LS_FLAG_A : i;
		i = (ft_strchr(arg[cnt], 'r') != NULL) ? i | LS_FLAG_MR : i;
		i = (ft_strchr(arg[cnt], 't') != NULL) ? i | LS_FLAG_T : i;
		i = (ft_strchr(arg[cnt], 'G') != NULL) ? i | LS_FLAG_G : i;
		i = (ft_strchr(arg[cnt], '1') != NULL) ? i | LS_FLAG_1 : i;
		i = (ft_strchr(arg[cnt], 'F') != NULL) ? i | LS_FLAG_F : i;
		i = (ft_strchr(arg[cnt], 'f') != NULL) ? i | LS_FLAG_MF | LS_FLAG_A : i;
		i = (ft_strchr(arg[cnt], 'm') != NULL) ? i | LS_FLAG_M : i;
		cnt++;
	}
	if (i != 0 || (i == 0 && cnt == 1))
		return (i);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putstr(&arg[--cnt][1]);
	ft_putstr("\nusage: ft_ls [-FGRaflmrt1] [file ...]\n");
	exit(0);
}

void		bsize(char *dir, t_dirent *files, int flag)
{
	t_stat	st;
	int		bs;
	char	*fp;

	if (!(flag & LS_FLAG_L))
		return ;
	bs = 0;
	while (files->d_name[0] != '\0')
	{
		fp = ft_strdup(dir);
		fp = free_join(fp, "/");
		fp = free_join(fp, files->d_name);
		stat(fp, &st);
		bs += st.st_blocks;
		free(fp);
		files++;
	}
	ft_putstr("total ");
	ft_putnbr_endl(bs);
}

char		**get_dir(int ac, char **av)
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
