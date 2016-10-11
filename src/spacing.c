/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:07:00 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/11 20:35:47 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

void	put_space(int nb, int max)
{
	int i;

	i = ft_tpow(nb);
	i = max - i;
	if (i < 0)
		i = ft_tpow(nb);
	while (i--)
		ft_putchar(' ');
}

int		get_flag(int i, char *arg)
{
	i = (ft_strchr(arg, 'l') != NULL) ? i | LS_FLAG_L : i;
	i = (ft_strchr(arg, 'R') != NULL) ? i | LS_FLAG_R : i;
	i = (ft_strchr(arg, 'a') != NULL) ? i | LS_FLAG_A : i;
	i = (ft_strchr(arg, 'r') != NULL) ? i | LS_FLAG_MR : i;
	i = (ft_strchr(arg, 't') != NULL) ? i | LS_FLAG_T : i;
	i = (ft_strchr(arg, 'G') != NULL) ? i | LS_FLAG_G : i;
	i = (ft_strchr(arg, 'F') != NULL) ? i | LS_FLAG_F : i;
	i = (ft_strchr(arg, 'f') != NULL) ? i | LS_FLAG_MF | LS_FLAG_A : i;
	i = (ft_strchr(arg, 'm') != NULL) ? i | LS_FLAG_M : i;
	i = (ft_strchr(arg, 'i') != NULL) ? i | LS_FLAG_I : i;
	i = (ft_strchr(arg, 'g') != NULL) ? i | LS_FLAG_MG | LS_FLAG_L: i;
	i = (ft_strchr(arg, 'n') != NULL) ? i | LS_FLAG_N | LS_FLAG_L -\
		LS_FLAG_MG : i;
	i = (ft_strchr(arg, 'O') != NULL) ? i | LS_FLAG_O : i;
	i = (ft_strchr(arg, 's') != NULL) ? i | LS_FLAG_MS : i;
	i = (ft_strchr(arg, 'u') != NULL) ? i | LS_FLAG_MU : i;
	return (i);
}
