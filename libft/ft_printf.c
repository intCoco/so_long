/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:20:47 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/14 13:14:33 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbase(ULL n, char *base, ULL baserange, char argtype)
{
	int		i;
	char	buffer[50];
	int		count;

	count = 0;
	i = 0;
	if (argtype == 'p')
		count += ft_putstr_pf("0x");
	while (n >= baserange)
	{
		buffer[i] = base[n % baserange];
		n /= baserange;
		i++;
	}
	if (n < baserange)
		buffer[i] = base[n % baserange];
	while (i >= 0)
		count += ft_putchar_pf(buffer[i--]);
	return (count);
}

static int	ft_write_arg(char argtype, va_list arg)
{
	if (argtype == 'c')
		return (ft_putchar_pf(va_arg(arg, int)));
	else if (argtype == 's')
		return (ft_putstr_pf(va_arg(arg, char *)));
	else if (argtype == 'p')
		return (ft_putbase((ULL)va_arg(arg, void *), HEXA_LOW, 16, argtype));
	else if (argtype == 'd' || argtype == 'i')
		return (ft_putnbr_pf(va_arg(arg, int)));
	else if (argtype == 'u')
		return (ft_putbase(va_arg(arg, unsigned int), DEC, 10, argtype));
	else if (argtype == 'x')
		return (ft_putbase(va_arg(arg, unsigned int), HEXA_LOW, 16, argtype));
	else if (argtype == 'X')
		return (ft_putbase(va_arg(arg, unsigned int), HEXA_UP, 16, argtype));
	else
		return (ft_putchar_pf(argtype));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_write_arg(format[i], arg);
		}
		else
			count += ft_putchar_pf(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
