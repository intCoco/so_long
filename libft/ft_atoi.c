/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:12:38 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/11 19:51:09 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conv_in_int(const char *str, int i)
{
	int	nbint;

	nbint = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbint = nbint * 10 + ((char *)str)[i] - '0';
		i++;
	}
	return (nbint);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbint;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nbint = ft_conv_in_int(str, i);
	nbint *= sign;
	return (nbint);
}
