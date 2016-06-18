/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/18 17:25:41 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "debug.h"

int	main(int ac, char **av)
{
	char 	**dir;
	int	arg;

	dbg_title("Starting");
	if (ac == 1)
	{
		dbg_info("main", "ac == 1", 0);
		if ((dir = (char **)ft_memalloc(1)) == NULL)
			exit(EXIT_FAILURE);
		dir[0] = ft_strdup("./");
		arg = 0;
	}
	else
	{
		dbg_info("main", "ac != 1", 0);
		dbg_info("main", "get dir", 1);
		dir = f_args(ac, av);
		dbg_info("main", "get args", 1);
		arg = get_args(ac, av);
		ac = (arg != 0) ? ac - 1 : ac;
		dbg_info("main", "endif", 0);
	}
	dbg_var_str("main", "dir[0]", dir[0], 0);
	f_ls(dir, ((ac == 1) ? ac : ac), arg);
	return (EXIT_SUCCESS);
}
