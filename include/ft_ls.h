/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:25:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/18 17:48:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include "debug.h"
# define LS_FLAG_L 0x01
# define LS_FLAG_R 0x02
# define LS_FLAG_A 0x04
# define LS_FLAG_MR 0x08
# define LS_FLAG_T 0x0F
# define LS_FLAG_G 0x10

typedef struct dirent	t_dirent;
typedef struct			s_file
{
	t_dirent	**f_list;
	char		*name;
	int			*hide;
	int			nb;
}						t_file;

char					**f_args(int ac, char **av);
int						get_args(int ac, char **av);
void					f_ls(char **dir, int size, int arg);
t_file					*f_get_file(char **dir, int size);
void					print_file(t_file *f_list, int size, int arg);
#endif
