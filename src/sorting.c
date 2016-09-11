#include <ft_ls.h>
#include <libft.h>
#include <debug.h>


void	sort(int flag, t_dirent *dir)
{
	unsigned int i;
	unsigned int nb;

	if (flag & LS_FLAG_T)
	{
		//time sorting
	}
	if (flag & LS_FLAG_MR)
	{
		i = 0;
		nb = 0;
		while (&dir[nb++] != NULL);//count number of value
		while (nb != 0)
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
	t_dirent	*tmp;

	dir = *f_list;
	exit_mem((tmp = (t_dirent *)ft_memalloc(sizeof(t_dirent*))));
	while (dir->d_name[0] != '\0')// [w] -> 1
	{
		i = 0;
		while (dir[i].d_name[0] != '\0')// [w] -> 2
		{
//			dbg_var_str("sort", "current file", dir[i].d_name, 3);
//			dbg_breakpoint("sort", 1);
			if (is_before(dir->d_name, dir[i].d_name))//TODO: comparaison de nom
			{
				ft_memswitch((void *)dir, (void *)&dir[i], sizeof(t_dirent));
//				ft_memcpy((void *)tmp, (void *)dir, sizeof(t_dirent));
//				ft_memcpy((void *)dir, (void *)&dir[i], sizeof(t_dirent));
//				ft_memcpy((void *)&dir[i], (void *)tmp, sizeof(t_dirent));
				break;//exit [w2] and return in [w1]
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






