/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:24 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/16 12:38:08 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>

void	opt_1(int flag, char *fp, char *file)
{
	t_stat	st;

	lstat(fp, &st);
	if (!(flag & LS_FLAG_A) && file[0] == '.')
		return;
	if (flag & LS_FLAG_I)
	{
		put_space((int)st.st_ino, 10);
		ft_putnbr((int)st.st_ino);
		ft_putchar(' ');
	}
	if (flag & LS_FLAG_MS)
	{
		put_space((int)st.st_blocks, 5);
		ft_putnbr((int)st.st_blocks);
		ft_putchar(' ');
	}
}
