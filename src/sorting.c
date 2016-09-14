#include <ft_ls.h>
#include <libft.h>
#include <debug.h>

void	sort(int flag, t_dirent *dir, char *path)
{
	unsigned int	i;
	unsigned int	nb;

	dbg_info("sorting", "Start sorting", 2);
	if (flag & LS_FLAG_T)
	{
		time_sort(dir, path);
	}
	if (flag & LS_FLAG_MR)
	{
		i = 0;
		nb = 0;
		while (dir[nb++].d_name[0] != '\0')
			;
		nb -= 2;
		while (nb > i)
		{
			ft_memswitch((void *)&dir[i], (void *)&dir[nb], sizeof(t_dirent));
			i++;
			nb--;
		}
	}
}

void	time_sort(t_dirent *dir, char *path)
{
	t_stat	m_stat;
	int		nb_file;
	int		i;
	int		*date;
	char	*file_path;

	nb_file = 0;
	i = 0;
	dbg_info("sort_time", "before count", 2);
	while (dir[nb_file].d_name[0] != '\0')
		nb_file++;
	dbg_info("sort_time", "before count", 2);
	date = (int *)ft_memalloc(sizeof(int) * nb_file);
	exit_mem((void *)date);
	//recup date
	while (i < nb_file)
	{
		file_path = ft_strdup(path);
		if (file_path[ft_strlen(file_path) - 1] != '/')
			file_path = free_join(file_path, "/");
		file_path = free_join(file_path, dir[i].d_name);
		dbg_var_str("sort_time", "file_path", file_path, 2);

		lstat(file_path, &m_stat);
		date[i] = m_stat.st_mtimespec.tv_sec;
		ft_strdel(&file_path);
		i++;
	}
	i = 0;
	while (i != nb_file)
	{
		printf("%d\t%s\n", date[i], dir[i].d_name);
		i++;
	}
//	dbg_var_array_int("sort_time", dir[i].d_name, date, 2);
	dbg_info("sort_time", "start sorting...", 2);
	i = 0;
	//SORT
	ft_tablesort(date, nb_file, dir);
	ft_memdel((void **)&date);
	dbg_info("sort_time", "Done !", 2);
}

void	sort_alpha(t_dirent **f_list)
{
	dbg_info("sort_alpha", "Starting...", 2);
	size_t		i;
	t_dirent	*dir;

	dir = *f_list;
	while (dir->d_name[0] != '\0')
	{
		i = 0;
		while (dir[i].d_name[0] != '\0')
		{
			if (ft_strcmp(dir->d_name, dir[i].d_name) > 0)
			{
				ft_memswitch((void *)dir, (void *)&dir[i], sizeof(t_dirent));
				dir = *f_list;
				i = 0;
				break ;
			}
			i++;
		}
		if (i != 0)
			dir++;
	}
	dbg_info("sort_alpha", "Done !", 2);
}

void	ft_tablesort(int *t, int len, t_dirent *d)
{
	int	i;
	int	x;

	i = 0;
	while (i < len)
	{
		x = i;
		while (x < len)
		{
			if (t[x] > t[i])
			{
				ft_memswitch((void *)&t[i], (void *)&t[x], sizeof(int));
				ft_memswitch((void *)&d[i], (void *)&d[x], sizeof(t_dirent));
				x = 0;
				i = 0;
				break ;
			}
			x++;
		}
		if (x != 0)
			i++;
	}
}
