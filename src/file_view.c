#include <ft_ls.h>
#include <debug.h>
#include <libft.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

void	permission(t_stat stat)
{
	ft_putchar(S_ISDIR(stat.st_mode) ? 'd' : (S_ISLNK(stat.st_mode) ? 'l' : '-'));
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

void	l_view(int flag, t_dirent *f_list, char *path)
{
	UNUSED(flag);
//	UNUSED(f_list);
//	UNUSED(path);
	t_stat	stat;
	char	*file_path;
	while (f_list->d_name[0] != '\0')
	{
		file_path = ft_strdup(path);
		file_path = free_join(file_path, "/");
		file_path = free_join(file_path, f_list->d_name);
		lstat(file_path, &stat);
		permission(stat);
		username(stat);
		ft_putnbr(stat.st_size);
		ft_putstr(stat.st_size > 9999 ? "\t" : "  \t");
		ft_putendl(f_list->d_name);
//		dbg_breakpoint("l_view", 1);
		f_list++;
	}
}
