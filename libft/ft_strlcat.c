/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:41:05 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/09 16:38:45 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (size == 0 && (dest == NULL || src == NULL))
		return (0);
	dlen = ft_strlen(dest);
	slen = ft_strlen((char *)src);
	i = dlen;
	j = 0;
	if (size < 1)
		return (slen + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (dlen < size)
		dest[i] = '\0';
	if (size < dlen)
		return (slen + size);
	else
		return (dlen + slen);
}
