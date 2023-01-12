/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:26:50 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/09 12:52:42 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t l)
{
	size_t	i;

	i = 0;
	if (l <= 0)
		return (0);
	while (((unsigned char *)p1)[i] == ((unsigned char *)p2)[i] && i < l - 1)
		i++;
	return (((unsigned char *)p1)[i] - ((unsigned char *)p2)[i]);
}
