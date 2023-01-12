/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:57:56 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/09 15:40:55 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t l)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char *)str);
	if (!str && l == 0)
		return (NULL);
	while (str[i] != '\0' && i < l)
	{
		j = 0;
		while (tofind[j] == str[i + j] && i + j < l)
		{
			if (tofind[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*char	*ft_strnstr(const char *str, const char *tofind, size_t l)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	//printf("%zu", l);
	if (*tofind == '\0')
		return ((char *)str);
	if (!str && l == 0)
		return (NULL);
	while (str[i1] && (i1 < l))
	{
		printf(" str[i1] = %c && tofind[i2] = %c \n", str[i1], tofind[i2]);
		printf("      i1 = %zu &&         i2 = %zu \n", i1, i2);
		if (str[i1] != tofind[i2])
			i2 = 0;
		if (str[i1] == tofind[i2])
		{
			i2++;
			if (tofind[i2] == '\0')
				return ((char *)str + (i1 - i2 + 1));
		}
		else
			i2 = 0;
		i1++;
	}
	return (NULL);
}

int main()

{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "abcd";
	printf("%s", ft_strnstr(haystack, needle, -1));
}*/