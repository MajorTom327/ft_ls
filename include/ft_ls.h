/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:25:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/08 12:43:00 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>

typedef struct dirent dirent;
typedef struct	s_file
{
	dirent	**f_list;
	int			*hide;
	int			nb
}		t_file;
char	**f_args(int ac, char **av);
int	get_args(int ac, char **av);
void	f_ls(char **dir, int size, int arg);
t_file	*f_get_file(char **dir, int size);
#endif
