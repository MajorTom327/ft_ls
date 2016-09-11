#ifndef FT_LS_H
# define FT_LS_H
# define LS_FLAG_L	0x01
# define LS_FLAG_R	0x02
# define LS_FLAG_A	0x04
# define LS_FLAG_MR	0x08
# define LS_FLAG_T	0x0F
# define LS_FLAG_G	0x10
# define LS_FLAG_1	0x20
# define LS_FLAG_F	0x40
# define LS_FLAG_MF	0x80
# define LS_FLAG_M	0xF0

# define UNUSED(x) (void)x
#include <dirent.h>
#include <sys/stat.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

int			get_arg(char *arg);
char		**get_dir(int ac, char **av);
t_dirent	*get_files(const char *dir_name);

void		main_view(int flag, char *str_dir);	
void		file_view(int flag, t_dirent *f_list, char *path);
void		l_view(int flag, t_dirent *f_list, char *path);
void		printname(int flag, t_stat stat, t_dirent file, char *path);

int			is_before(const char *first, const char *next);
void		sort_alpha(t_dirent **f_list);
void		sort(int flag, t_dirent *dir);

void		exit_failure(void);
void		exit_mem(void *mem);

#endif
