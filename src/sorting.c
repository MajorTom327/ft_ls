#include <ft_ls.h>
#include <libft.h>
#include <debug.h>

void	sort(int flag, t_dirent *dir)
{
	unsigned int	i;
	unsigned int	nb;

	dbg_info("sorting", "Start sorting", 2);
	if (flag & LS_FLAG_T)
	{
		//TODO:time sorting
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
			if (is_before(dir->d_name, dir[i].d_name))
			{
				ft_memswitch((void *)dir, (void *)&dir[i], sizeof(t_dirent));
				dir = *f_list;
				break ;
			}
			i++;
		}
		dir++;
	}
}

int		is_before(const char *first, const char *next)
{
	int i;

	i = 0;
	while (first[i] && next[i])
	{
		if (first[i] > next[i])
			return (1);
		if (first[i] < next[i])
			return (0);
		i++;
	}
	return (0);
}
