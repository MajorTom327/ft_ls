/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 21:59:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/07/16 04:11:34 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include <unistd.h>

void	dbg_breakpoint(const char *f, size_t lvl);
void	dbg_title(const char *str);
void	dbg_info(const char *f, const char *data, size_t lvl);
void	dbg_diff_int(const char *f, const char *name, int v, int st, size_t lvl);
void	dbg_var_char(const char *f, const char *name, const char c, size_t lvl);
void	dbg_var_str(const char *f, const char *name, const char *str, size_t lvl);
void	dbg_var_int(const char *f, const char *name, const int c, size_t lvl);
void	dbg_var_array_int(const char *f, const char *name, const int *str, size_t lvl);
void	dbg_var_array_char(const char *f, const char *name, const char *str, size_t lvl);
void	dbg_var_array_str(const char *f, const char *name, const char **str, size_t lvl);
size_t	ft_strlen(char const *s);
void	ft_putnbr(int n);
void	ft_spacelevel(size_t lvl);
#endif
