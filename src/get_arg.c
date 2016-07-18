#include <ft_ls.h>
#include <libft.h>
#include <debug.h>

int		get_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != '-')
		return (0);
	i = (ft_strchr(arg, 'l') != NULL) ? i | 0x01 : i;
	i = (ft_strchr(arg, 'R') != NULL) ? i | 0x02 : i;
	i = (ft_strchr(arg, 'a') != NULL) ? i | 0x04 : i;
	i = (ft_strchr(arg, 'r') != NULL) ? i | 0x08 : i;
	i = (ft_strchr(arg, 't') != NULL) ? i | 0x0F : i;
	i = (ft_strchr(arg, 'G') != NULL) ? i | 0x10 : i;
	i = (ft_strchr(arg, '1') != NULL) ? i | 0x20 : i;
	i = (ft_strchr(arg, 'F') != NULL) ? i | 0x40 : i;
	dbg_var_int("get_arg", "argument value:", i, 1);
	return (i);
}

char	**get_dir(int ac, char **av)
{
	char **dir;

	dbg_info("get_dir", "Getting directory...", 1);
	dir = ft_memalloc(sizeof(char *) * (ac + 1));
	exit_mem((void *) dir);
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
		exit_mem((void *) dir[ac]);
	}
	dbg_info("get_dir", "Many directory found !", 1);
	if (dir[0][0] == '-')
		return (&dir[1]);
	return (dir);
}

//TODO: Maybe somes fixes will be needed
t_dirent *get_files(const char *dir_name)
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
		ft_memcpy((void *)&files[--i],(void *)tmp, sizeof(t_dirent));
	closedir(directory);
	return (files);
}
