/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:24:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/08 12:44:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int	main(int ac, char **av)
{
	char 	**dir;
	int	arg;

	if (ac == 1)
	{
		if ((dir = (char **)ft_memalloc(1)) == NULL)
			exit(EXIT_FAILURE);
		dir[0] = ft_strdup("./");
		arg = 0;
	}
	else
	{
		dir = f_args(ac, av);
		arg = get_args(ac, av);
	}
	f_ls(dir, ac, arg);
	return (EXIT_SUCCESS);
}
