/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:16:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/14 03:45:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ft_ls.h>

void	sf_mainloop(int flag, char **dir, int st)
{
	int		cnt;

	cnt = 0;
	while (dir[cnt][0] != '\0')
	{
		if (st != 1)
		{
			if (cnt || st > 1)
				ft_putchar('\n');
			ft_putstr(dir[cnt]);
			ft_putendl(":");
		}
		main_view(flag, dir[cnt]);
		cnt++;
	}
}

int			main(int ac, char **av)
{
	char	**dir;
	int		flag;
	int		i;

	flag = 0;
	if (ac > 1)
		flag = get_arg(av, ac);
	dir = get_dir(ac, av, &i);
	sf_mainloop(flag, dir, i - 1);
	if (flag != 0)
		ft_memdel((void **)--dir);
	else
		ft_memdel((void **)dir);
	while (1);
	return (0);
}
