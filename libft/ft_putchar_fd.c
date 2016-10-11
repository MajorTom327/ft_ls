/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:00:39 by vthomas           #+#    #+#             */
/*   Updated: 2015/12/16 13:30:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(unsigned short c, int fd)
{
	write(fd, (void *)&c, 1);
}

void		ft_putchar_fd(char c, int fd)
{
	unsigned short my_letter;

	if (c < 0)
	{
		my_letter = (unsigned char)(0xFF & c);
		print((0xC0) | (my_letter >> 6), fd);
		print((0x80) | (my_letter & 0x3F), fd);
	}
	else
		write(fd, &c, 1);
}
