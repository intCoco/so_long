/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:52:06 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/13 16:40:00 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t l)
{
	char	*s;
	size_t	i;

	s = (void *)malloc(l * c);
	if (!s)
		return (NULL);
	if (l > SIZE_MAX / c)
		return (NULL);
	i = -1;
	while (++i < c * l)
		*(unsigned char *)(s + i) = 0;
	return (s);
}
