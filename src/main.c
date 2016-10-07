#include "libft.h"
#include <ft_ls.h>

void	sf_mainloop(int flag, char **dir)
{
	char	**tmp;
	int		cnt;

	tmp = dir;
	cnt = 0;
	while (*dir)
	{
		dir++;
		cnt++;
	}
	dir = tmp;
	while (*dir)
	{
		if (cnt > 1)
		{
			ft_putchar('\n');
			ft_putstr(*dir);
			ft_putendl(":");
		}
		main_view(flag, *dir);
		dir++;
	}
}

int			main(int ac, char **av)
{
	char	**dir;
	int		flag;

	flag = 0;
	if (ac > 2)
		flag = get_arg(av, ac);
	dir = get_dir(ac, av);
	sf_mainloop(flag, dir);
	if (flag != 0)
		ft_memdel((void **)--dir);
	else
		ft_memdel((void **)dir);
	return (0);
}
