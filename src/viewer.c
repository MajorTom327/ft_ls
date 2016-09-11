#include <ft_ls.h>
#include "libft.h"
#include "debug.h"

//TODO: Change the temporary prototype to a prototype in ft_ls.h
void file_view(int flag, t_dirent *f_list);

void main_view(int flag, char *str_dir)
{
	t_dirent *files;

	UNUSED(flag);
	files = get_files(str_dir);
	dbg_info("main_view", "Files get OK", 1);
	file_view(flag, files);
	ft_memdel((void **)&files); 
}

void file_view(int flag, t_dirent *f_list)
{
	sort_alpha(&f_list);
	dbg_info("file_view", "Sorting done !", 2);
	if (flag & (LS_FLAG_T | LS_FLAG_MR))
		sort(flag, f_list);
	UNUSED(flag);
	UNUSED(f_list);
}
