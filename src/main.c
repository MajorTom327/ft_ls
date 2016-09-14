#include "libft.h"
#include <ft_ls.h>
#include "debug.h"

static void	sf_mainloop(int flag, char **dir)
{
	char **tmp;
	int cnt;

	tmp = dir;
	cnt = 0;
	while (*dir)
	{
		dir++;
		cnt++;
	}
	dir = tmp;
	dbg_title("MAIN LOOP");
	while (*dir)
	{
		if (cnt > 1)
		{
			ft_putstr(*dir);
			ft_putendl(":");
		}
		main_view(flag, *dir);
		dir++;
	}
	dbg_title("EXITING MAIN LOOP");
}

int			main(int ac, char **av)
{
	char	**dir;
	int		flag;
	int		count;

	UNUSED(count);
	flag = 0;
	dbg_title("FT_LS");
	dbg_var_int("main", "ac", ac, 0);
	if (ac > 1)
		flag = get_arg(av, ac);
	dir = get_dir(ac, av);
	dbg_var_array_str("main", "dir list", (const char **)dir, 0);
	sf_mainloop(flag, dir);
	dbg_title("FREEING THE MEMORY");
	if (flag != 0)
		ft_memdel((void **)--dir);
	else
		ft_memdel((void **)dir);
	dbg_title("END FT_LS");
	return (0);
}
