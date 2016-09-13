#include <ft_ls.h>
#include <libft.h>
#include <debug.h>

static void	simple_list(int flag, t_dirent *f_list, char *path)
{
	t_stat	stat;

	while (f_list->d_name[0] != '\0')
	{
		lstat(path, &stat);
		if (!(flag & LS_FLAG_A) && f_list->d_name[0] == '.')
		{
			f_list++;
			continue;
		}
		printname(flag, stat, *f_list, path);
		ft_putchar('\n');
		f_list++;
	}
}

void		main_view(int flag, char *str_dir)
{
	t_dirent *files;

	files = get_files(str_dir);
	dbg_info("main_view", "Files get OK", 1);
	dbg_var_str("main_view", "str_dir", str_dir, 2);
	file_view(flag, files, str_dir);
	ft_memdel((void **)&files);
}

void		file_view(int flag, t_dirent *f_list, char *path)
{
	if (!(flag & LS_FLAG_MF))
		sort_alpha(&f_list);
	dbg_info("file_view", "Sorting done !", 2);
	if ((flag & (LS_FLAG_T | LS_FLAG_MR)) && !(flag & LS_FLAG_MF))
		sort(flag, f_list);
	if (flag & LS_FLAG_L)
		l_view(flag, f_list, path);
	else
		simple_list(flag, f_list, path);
}
