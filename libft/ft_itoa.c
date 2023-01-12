/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:48:57 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/12 23:30:59 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int		count;

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

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	nb;

	nb = n;
	i = ft_count(nb);
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
