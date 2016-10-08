#include <ft_ls.h>
#include <libft.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>

static void	permission(t_stat stat)
{
	if (S_ISDIR(stat.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(stat.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(stat.st_mode))
		ft_putchar('c');
	else if (S_ISSOCK(stat.st_mode))
		ft_putchar('s');
	else if (S_ISBLK(stat.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(stat.st_mode))
		ft_putchar('p');
	else
		ft_putchar('-');
	ft_putchar((stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((stat.st_mode & S_IXOTH) ? 'x' : '-');
}

static void	username(t_stat stat)
{
	struct passwd	*usr;
	struct group	*grp;

	ft_putstr("  ");
	ft_putnbr(stat.st_nlink);
	ft_putstr("  ");
	usr = getpwuid(stat.st_uid);
	ft_putstr(usr->pw_name);
	ft_putstr("  ");
	grp = getgrgid(stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
}

static void	last_time(t_stat m_stat, char *path)
{
	char *tmp;

	if (S_ISLNK(m_stat.st_mode))
	{
		lstat(path, &m_stat);
	}
	tmp = ctime(&m_stat.st_mtimespec.tv_sec);
	tmp += 4;
	tmp[ft_strlen(tmp) - 9] = '\0';
	ft_putstr(tmp);
	ft_putchar(' ');
}

void		l_view(int flag, t_dirent *f_list, char *path)
{
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
		ft_putnbr((int)stat.st_size);
		ft_putstr(stat.st_size > 9999 ? "\t" : ((stat.st_size < 10) ?\
			"\t\t" : "  \t"));
		last_time(stat, file_path);
		printname(flag, stat, *f_list, file_path);
		ft_putchar('\n');
		ft_strdel(&file_path);
		f_list++;
	}
}
