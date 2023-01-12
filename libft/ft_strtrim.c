/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:02:31 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/12 15:49:16 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkcharset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (ft_checkcharset(s1[i], (char *)set) == 1 && s1[i])
		i++;
	while ((ft_checkcharset(s1[j], (char *)set) == 1 && j > i) || s1[j] == '\0')
		j--;
	s2 = ft_substr(s1, i, j - i + 1);
	return (s2);
}
