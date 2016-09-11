#include <ft_ls.h>
#include <debug.h>
#include <libft.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>

void	permission(t_stat stat)
{
	char c;

	if (S_ISDIR(stat.st_mode))
		c = 'd';
	else if (S_ISLNK(stat.st_mode))
		c = 'l';
	else if (S_ISCHR(stat.st_mode))
		c = 'c';
	else if (S_ISSOCK(stat.st_mode))
		c = 's';
	else if (S_ISBLK(stat.st_mode))
		c = 'b';
	else if (S_ISFIFO(stat.st_mode))
		c = 'p';
	else
		c = '-';
	ft_putchar(c);
	ft_putchar((stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
	ft_putnbr(stat.st_nlink);
	ft_putstr("  ");
}

void	username(t_stat stat)
{
	struct passwd	*usr;
	struct group	*grp;

	usr = getpwuid(stat.st_uid);
	ft_putstr(usr->pw_name);
	ft_putstr("  ");
	grp = getgrgid(stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
}

void	last_time(t_stat m_stat, char *path)
{
	char *tmp;

	if (S_ISLNK(m_stat.st_mode))
	{
		ft_putendl_fd("LINK", 2);
		stat(path, &m_stat);
	}
	tmp = ctime(&m_stat.st_atimespec.tv_sec);
	tmp += 4;
	tmp[ft_strlen(tmp) - 9] = '\0';
	ft_putstr(tmp);
	ft_putchar(' ');
}

void	l_view(int flag, t_dirent *f_list, char *path)
{
	UNUSED(flag);
//	UNUSED(f_list);
//	UNUSED(path);
	t_stat	stat;
	char	*file_path;
	while (f_list->d_name[0] != '\0')
	{
		if (!(flag & LS_FLAG_A) && f_list->d_name[0] == '.')
		{
			f_list++;
			continue;
		}
		file_path = ft_strdup(path);
		file_path = free_join(file_path, "/");
		file_path = free_join(file_path, f_list->d_name);
		lstat(file_path, &stat);
		permission(stat);
		username(stat);
		ft_putnbr(stat.st_size);
		ft_putstr(stat.st_size > 9999 ? "\t" : "  \t");
		last_time(stat, file_path);
//		ft_putstr(ctime(&stat.st_atimespec.tv_sec));
		ft_putendl(f_list->d_name);
//		dbg_breakpoint("l_view", 1);
		f_list++;
	}
}
