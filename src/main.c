#include "libft.h"
#include <ft_ls.h>

void	sf_mainloop(int flag, char **dir, int st)
{
	int		cnt;

	cnt = 0;
	while (dir[cnt][0] != '\0')
	{
		if (cnt != 0 && !st)
		{
			ft_putchar('\n');
			ft_putstr(dir[cnt]);
			ft_putendl(":");
		}
		main_view(flag, dir[cnt]);
		cnt++;
	}
}

int			main(int ac, char **av)
{
	char	**dir;
	int		flag;

	flag = 0;
	if (ac > 1)
		flag = get_arg(av, ac);
	dir = get_dir(ac, av);
	sf_mainloop(flag, dir, 1);
	if (flag != 0)
		ft_memdel((void **)--dir);
	else
		ft_memdel((void **)dir);
	return (0);
}
