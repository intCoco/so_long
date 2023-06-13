/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/13 22:06:01 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_checkmapname(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i + 1])
		i++;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		return (1);
	return (0);
}

int	main_args_parsing(int ac, char **av)
{
	if (ft_strncmp(av[0], "./so_long", -1) != 0)
		return (ft_printf("Please run the program directly from the"
				"main directory\n"));
	if (ac > 2)
		return (ft_printf("Error\nToo many arguments\n"));
	if (ac == 1)
		return (ft_printf("Error\nPlease,"
				"make sure to inform the map's name\n"));
	else if (ft_checkmapname(av[1]) == 1)
		return (ft_printf("Error\nInvalid map name\nMake sure your map file"
				"ends with \".ber\"\n"));
	return (0);
}
