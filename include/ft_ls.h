#ifndef FT_LS_H
# define FT_LS_H
# define LS_FLAG_L	0x0001
# define LS_FLAG_R	0x0002
# define LS_FLAG_A	0x0004
# define LS_FLAG_MR	0x0008
# define LS_FLAG_T	0x0010
# define LS_FLAG_G	0x0020
# define LS_FLAG_1	0x0040
# define LS_FLAG_F	0x0080
# define LS_FLAG_MF	0x0100
# define LS_FLAG_M	0x0200

# include <dirent.h>
# include <sys/stat.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

void		sf_mainloop(int flag, char **dir, int st);

int			get_arg(char **arg, int ac);
char		**get_dir(int ac, char **av);
t_dirent	*get_files(char *dir_name);

void		main_view(int flag, char *str_dir);
void		file_view(int flag, t_dirent *f_list, char *path);
void		l_view(int flag, t_dirent *f_list, char *path);
void		printname(int flag, t_stat stat, t_dirent file, char *path);

void		sort_alpha(t_dirent **f_list);
void		sort(int flag, t_dirent *dir, char *path);
void		time_sort(t_dirent *dir, char *path);
void		ft_tablesort(int *t, int len, t_dirent *d);

void		exit_failure(void) __attribute__ ((noreturn));
void		exit_mem(void *mem);

#endif
