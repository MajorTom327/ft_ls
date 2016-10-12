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
# define LS_FLAG_I	0x0400
# define LS_FLAG_MG	0x0800
# define LS_FLAG_N	0x1000
# define LS_FLAG_O	0x2000
# define LS_FLAG_MS	0x4000
# define LS_FLAG_MU	0x8000

# ifdef __gnu_linux__
#  define st_mtimespec st_mtim
#  define st_ctimespec st_ctim
# endif


# include <dirent.h>
# include <sys/stat.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

void		sf_mainloop(int flag, char **dir, int st);

int			get_arg(char **arg, int ac);
int			get_flag(int i, char *arg);
char		**get_dir(int ac, char **av, int *cnt);
t_dirent	*get_files(char *dir_name);
void		bsize(char *dir, t_dirent *f, int flag);

void		main_view(int flag, char *str_dir);
void		file_view(int flag, t_dirent *f_list, char *path);
void		l_view(int flag, t_dirent *f, char *path);
void		printname(int flag, t_stat stat, t_dirent file, char *path);

void		sort_alpha(t_dirent **f_list);
void		sort(int flag, t_dirent *dir, char *path);
void		time_sort(t_dirent *dir, char *path, int flag);
void		ft_tablesort(int *t, int len, t_dirent *d);

void		exit_failure(void) __attribute__ ((noreturn));
void		exit_mem(void *mem);
void		*exit_dir(char *dir_name);

void		put_space(int nb, int max);
void		opt_1(int flag, char *fp, char *file);

#endif
