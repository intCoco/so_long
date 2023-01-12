/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:16:40 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/09 11:40:48 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	size_t	i;

	i = 0;
	if (l <= 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& ((unsigned char *)s1)[i] && ((unsigned char *)s2)[i] && i < l - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
