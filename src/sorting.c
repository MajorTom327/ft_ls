#include <ft_ls.h>
#include <libft.h>

void	sort(int flag, t_dirent *dir, char *path)
{
	unsigned int	i;
	unsigned int	nb;

	if (flag & LS_FLAG_T)
		time_sort(dir, path);
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
	t_stat			m_stat;
	unsigned int	nb_file;
	unsigned int	i;
	int				*date;
	char			*file_path;

	nb_file = 0;
	i = 0;
	while (dir[nb_file].d_name[0] != '\0')
		nb_file++;
	exit_mem((void *)(date = (int *)ft_memalloc(sizeof(int) * nb_file)));
	while (i < nb_file)
	{
		file_path = ft_strdup(path);
		exit_mem(file_path);
		if (file_path[ft_strlen(file_path) - 1] != '/')
			file_path = free_join(file_path, "/");
		file_path = free_join(file_path, dir[i].d_name);
		lstat(file_path, &m_stat);
		date[i] = (int)m_stat.st_mtimespec.tv_sec;
		ft_strdel(&file_path);
		i++;
	}
	ft_tablesort(date, (int)nb_file, dir);
	ft_memdel((void **)&date);
}

void	sort_alpha(t_dirent **f_list)
{
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
