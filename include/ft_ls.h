#ifndef FT_LS_H
# define FT_LS_H
# define LS_FLAG_L	0x01
# define LS_FLAG_R	0x02
# define LS_FLAG_A	0x04
# define LS_FLAG_MR	0x08
# define LS_FLAG_T	0x0F
# define LS_FLAG_G	0x10
# define LS_FLAG_1	0x20
# define UNUSED(x) (void)x
#include <dirent.h>

typedef struct dirent	t_dirent;

int			get_arg(char *arg);
char		**get_dir(int ac, char **av);
t_dirent	*get_files(const char *dir_name);
void		main_view(int flag, char *str_dir);
void		exit_failure(void);
void		exit_mem(void *mem);
#endif
