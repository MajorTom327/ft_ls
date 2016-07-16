#include <libft.h>
#include <ft_ls.h>
#include <debug.h>

static void sf_mainloop(int flag, char **dir)
{
	dbg_title("MAIN LOOP");
	while (*dir)
	{
		ft_putendl(*dir);
		dir++;
	}
	dbg_title("EXITING MAIN LOOP");
}

int main(int ac, char **av)
{
	char	**dir;
	int		flag;
	int		count;

	dbg_title("FT_LS");
	dbg_var_int("main", "ac", ac, 0);
	if (ac > 1)
		flag = get_arg(av[1]);
	dir = get_dir(ac, av);
	dbg_var_array_str("main", "dir list", dir, 0);
	//Going in the main loop
	sf_mainloop(flag, dir);
	dbg_title("FREEING THE MEMORY");
	if (flag != 0)
		ft_memdel(--dir);
	else
		ft_memdel(dir);
	dbg_title("END FT_LS");
	return (0);
}
