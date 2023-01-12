/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:50:05 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/10 19:23:59 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t l)
{
	char			*res;
	size_t			i;
	unsigned int	slen;

	i = -1;
	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (l > slen)
		l = slen;
	res = malloc(l + 1);
	if (!res)
		return (NULL);
	ft_memset(res, '\0', l + 1);
	if (start >= slen)
		return (ft_memset(res, '\0', l));
	if (start < slen)
	{
		if (start < 0)
			start = slen + start;
		while (++i < l && str[start + i])
			res[i] = ((char *)str)[start + i];
	}
	res[i] = '\0';
	return (res);
}
