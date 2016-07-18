#include <ft_ls.h>
#include <libft.h>

//TODO: Change the temporary prototype to a prototype in ft_ls.h
void file_view(int flag, t_dirent *f_list);

void main_view(int flag, char *str_dir)
{
	t_dirent *files;

	files = get_files(str_dir);
	dbg_info("main_view", "Files get OK", 1);
	ft_memdel(&files); 
}

void file_view(int flag, t_dirent *f_list)
{
}
