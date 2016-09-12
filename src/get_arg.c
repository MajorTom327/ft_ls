#include <ft_ls.h>
#include <libft.h>
#include <debug.h>

/*
** get_arg
** Get arg is the function who will transforme char arg in a int value.
*/

int			get_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != '-')
		return (0);
	i = (ft_strchr(arg, 'l') != NULL) ? i | LS_FLAG_L : i;
	i = (ft_strchr(arg, 'R') != NULL) ? i | LS_FLAG_R : i;
	i = (ft_strchr(arg, 'a') != NULL) ? i | LS_FLAG_A : i;
	i = (ft_strchr(arg, 'r') != NULL) ? i | LS_FLAG_MR : i;
	i = (ft_strchr(arg, 't') != NULL) ? i | LS_FLAG_T : i;
	i = (ft_strchr(arg, 'G') != NULL) ? i | LS_FLAG_G : i;
	i = (ft_strchr(arg, '1') != NULL) ? i | LS_FLAG_1 : i;
	i = (ft_strchr(arg, 'F') != NULL) ? i | LS_FLAG_F : i;
	i = (ft_strchr(arg, 'f') != NULL) ? i | LS_FLAG_MF | LS_FLAG_A : i;
	i = (ft_strchr(arg, 'm') != NULL) ? i | LS_FLAG_M : i;
	if (i == 0)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putstr(&arg[1]);
		ft_putstr("\nusage: ft_ls [-FGRaflmrt1] [file ...]\n");
		exit(0);
	}
	dbg_var_int("get_arg", "argument value", i, 1);
	return (i);
}

char		**get_dir(int ac, char **av)
{
	char **dir;

	dbg_info("get_dir", "Getting directory...", 1);
	dir = ft_memalloc(sizeof(char *) * (ac + 1));
	exit_mem((void *)dir);
	if (ac == 1)
	{
		dir[0] = ft_strdup("./");
		dbg_info("get_dir", "Local directory found !", 1);
		return (dir);
	}
	ac--;
	while (--ac >= 0)
	{
		dir[ac] = ft_strdup(av[ac + 1]);
		exit_mem((void *)dir[ac]);
	}
	dbg_info("get_dir", "Many directory found !", 1);
	if (dir[0][0] == '-')
		return (&dir[1]);
	return (dir);
}

t_dirent	*get_files(const char *dir_name)
{
	DIR			*directory;
	t_dirent	*files;
	t_dirent	*tmp;
	int			i;

	directory = opendir(dir_name);
	exit_mem((void *)directory);
	i = 0;
	while ((tmp = readdir(directory)) != NULL)
		i++;
	closedir(directory);
	directory = opendir(dir_name);
	exit_mem((void *)directory);
	files = ft_memalloc(sizeof(t_dirent) * i);
	exit_mem(files);
	while ((tmp = readdir(directory)) != NULL)
		ft_memcpy((void *)&files[--i], (void *)tmp, sizeof(t_dirent));
	closedir(directory);
	return (files);
}
