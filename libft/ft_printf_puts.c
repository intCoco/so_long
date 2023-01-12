/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:21:33 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/13 19:03:42 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10 && count++ >= 0)
		n /= 10;
	return (count + 1);
}

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_pf("(null)"));
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

int	ft_putnbr_pf(int nb)
{
	int	i;

	i = ft_count(nb);
	if (nb == -2147483648)
	{
		ft_putchar_pf('-');
		ft_putchar_pf('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_pf('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_pf(nb / 10);
		ft_putnbr_pf(nb % 10);
	}
	else
		ft_putchar_pf(nb + '0');
	return (i);
}
