/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:35 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/09 12:50:44 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		while (len-- > 0)
			((char *)dest)[len] = ((char *)src)[len];
	else
		while (++i < len)
			((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
