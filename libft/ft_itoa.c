/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:54:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/11 21:48:08 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*f_intmin(void)
{
	char *str;

	str = ft_strnew(11);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

static char	*func_zero(int n)
{
	char *str;

	if (n == -2147483648)
		return (f_intmin());
	str = ft_strnew(1);
	str[0] = '0';
	return (str);
}

static int	ft_ilong(int nb)
{
	int len;

	len = -1;
	nb *= (nb < 0) ? -1 : 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	signe(int *n, char *str)
{
	if (*n < 0)
	{
		*n *= -1;
		str[0] = '-';
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*str;
	int		min;

	tmp = n;
	if (n == 0 || n == -2147483648)
		return (func_zero(n));
	len = (n < 0) ? ft_ilong(tmp) + 1 : ft_ilong(tmp);
	str = ft_strnew((size_t)len + 1);
	if (str == NULL)
		return (NULL);
	min = (n < 0) ? 1 : 0;
	signe(&n, str);
	while (len >= min)
	{
		tmp = n % 10;
		str[len] = '0' + tmp;
		n /= 10;
		len--;
	}
	return (str);
}
