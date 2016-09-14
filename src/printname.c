#include <libft.h>
#include <ft_ls.h>
#include <unistd.h>

static void	printcolor(t_stat stat)
{
	if (S_ISLNK(stat.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISDIR(stat.st_mode))
		ft_putstr("\033[34m");
	else if (stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		ft_putstr("\033[31m");
}

static void	printchar(t_stat stat)
{
	if (S_ISDIR(stat.st_mode))
		ft_putchar('/');
	else if (S_ISLNK(stat.st_mode))
		ft_putchar('@');
	else if (S_ISSOCK(stat.st_mode))
		ft_putchar('=');
	else if (S_ISFIFO(stat.st_mode))
		ft_putchar('|');
	else if (stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		ft_putchar('*');
}

void		printname(int flag, t_stat stat, t_dirent file, char *path)
{
	char *buf;

	exit_mem((buf = ft_strnew(255)));
	if (flag & LS_FLAG_G)
		printcolor(stat);
	ft_putstr(file.d_name);
	if (flag & LS_FLAG_G)
		ft_putstr("\033[0m");
	if (flag & LS_FLAG_F)
		printchar(stat);
	if (S_ISLNK(stat.st_mode) && !(flag & LS_FLAG_L))
	{
		ft_putstr(" -> ");
		buf = ft_strnew(1024);
		readlink(path, buf, 1024);
		ft_putstr(buf);
	}
	ft_strdel(&buf);
}
