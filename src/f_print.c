/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 07:49:38 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/03 09:15:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file(t_file *f_list, int size, int arg)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		if (size > 1)
		{
			if (j)
				write(1, "\n\n", 2);
			ft_putstr(f_list[j].name);
			write(1, ":\n", 2);
		}
		while (i < f_list[j].nb)
		{
			ft_putstr(f_list[j].f_list[i]->d_name);
			ft_putstr("\t");
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}
