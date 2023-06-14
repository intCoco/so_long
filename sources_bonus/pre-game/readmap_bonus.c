/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:20:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:50 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

char	*ft_returngnl(char *buffer, char *stock, int nb_read)
{
	free(buffer);
	if (nb_read == -1)
		return (0);
	return (stock);
}

char	*ft_read(int fd, char *stock)
{
	int		nb_read;
	char	*buffer;
	char	*tmp;

	buffer = ft_calloc(1 + 1, sizeof(char));
	if (!buffer)
		return (0);
	nb_read = read(fd, buffer, 1);
	if (nb_read < 1)
		return (ft_returngnl(buffer, stock, nb_read));
	if (!stock)
		stock = ft_calloc(1, sizeof(char));
	if (!stock)
		return (NULL);
	while (nb_read > 0)
	{
		buffer[nb_read] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, buffer);
		free(tmp);
		nb_read = read(fd, buffer, 1);
	}
	return (ft_returngnl(buffer, stock, nb_read));
}

char	*get_file(int fd)
{
	static char	*stock[4096];
	char		*file;

	file = ft_read(fd, stock[fd]);
	if (!file)
		return (NULL);
	return (file);
}

char	**ft_readmap(int fd)
{
	char	**map;
	char	*file;

	file = get_file(fd);
	if (!file)
		return (0);
	map = ft_split(file, '\n');
	free(file);
	if (!map)
		return (0);
	return (map);
}
