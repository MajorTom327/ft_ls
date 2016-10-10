#include <ft_ls.h>
#include <libft.h>

static void	simple_list(int flag, t_dirent *f_list, char *path)
{
	t_stat	st;
	char	*str;

	while (f_list->d_name[0] != '\0')
	{
		str = ft_strdup(path);
		str = free_join(str, "/");
		str = free_join(str, f_list->d_name);
		lstat(str, &st);
		ft_strdel(&str);
		if (!(flag & LS_FLAG_A) && f_list->d_name[0] == '.')
		{
			f_list++;
			continue;
		}
		printname(flag, st, *f_list, path);
		ft_putchar('\n');
		f_list++;
	}
}

void		main_view(int flag, char *str_dir)
{
	t_dirent	*files;
	t_stat		stat;
	char		*fp;
	char		**fn_list;
	int			cnt;

	files = get_files(str_dir);//TODO: ICI
	if (files == NULL)
		return ;
	file_view(flag, files, str_dir);
	if (flag & LS_FLAG_R)
	{
		cnt = 0;
		while (files[cnt].d_name[0] != '\0')
			cnt++;
		exit_mem((fn_list = (char **)malloc(sizeof(char *) * (size_t)cnt + 1)));
		cnt = 0;
		while (files->d_name[0] != '\0')
		{
			fp = ft_strdup(str_dir);
			exit_mem(fp);
			if (fp[ft_strlen(fp) - 1] != '/')
				fp = free_join(fp, "/");
			fp = free_join(fp, files->d_name);
			lstat(fp, &stat);
			if (S_ISDIR(stat.st_mode) && ft_strcmp(files->d_name, ".") != 0 &&\
				ft_strcmp(files->d_name, "..") != 0)
			{
				if (files->d_name[0] != '.' || flag & LS_FLAG_A)
				{
					fn_list[cnt] = ft_strdup(fp);
					cnt++;
				}
			}
			ft_strdel(&fp);
			files++;
		}
		if (cnt != 0)
		{
			fn_list[cnt] = ft_strnew(0);
			sf_mainloop(flag, fn_list);
			ft_memdel((void **)&fn_list);
		}
	}
}

void		file_view(int flag, t_dirent *f_list, char *path)
{
	if (!(flag & LS_FLAG_MF))
		sort_alpha(&f_list);
	if ((flag & (LS_FLAG_T | LS_FLAG_MR)) && !(flag & LS_FLAG_MF))
		sort(flag, f_list, path);
	if (flag & LS_FLAG_L)
		l_view(flag, f_list, path);
	else
		simple_list(flag, f_list, path);
}
