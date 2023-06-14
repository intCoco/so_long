/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:47 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

// Prints every steps of pathfinding.

/*void	ft_print_pathfinding(t_map map)
{
	usleep(200000);
	printf("\n");
	for (int i = 0; i < map.size.x + 1; i++)
		printf("----");
	printf("-\n");
	for (int i = 0; i < map.size.y + 1; i++)
	{
		for (int j = 0; j < map.size.x + 1; j++)
		{
			if (map.tab[i][j] >= 'a' && map.tab[i][j] <= 'z')
				printf("| "	"\033[0;31m" "%c " "\033[0m", map.tab[i][j]);
			else
				printf("| %c ", map.tab[i][j]);
		}
		printf("|\n");
		for (int i = 0; i < map.size.x + 1; i++)
			printf("----");
		printf("-\n");
	}
}*/

// Checks the reachable coordinates of the map.
// If a '0' is reachable, it becomes an 'x' and
// the other chars are lowered if they're reachable.

void	ft_pathfinding(t_map *map, int x, int y)
{
	if (map->tab[y][x] == '1' || map->tab[y][x] == 'x'
		|| map->tab[y][x] == 'c' || map->tab[y][x] == 'e'
		|| map->tab[y][x] == 'p' || map->tab[y][x] == 'f')
		return ;
	if (map->tab[y][x] == '0')
		map->tab[y][x] = 'x';
	else if (map->tab[y][x] == 'P')
		map->tab[y][x] = 'p';
	else if (map->tab[y][x] == 'C')
		map->tab[y][x] = 'c';
	else if (map->tab[y][x] == 'E')
		map->tab[y][x] = 'e';
	else if (map->tab[y][x] == 'M')
		map->tab[y][x] = 'm';
	if (map->tab[y][x] == 'x' || map->tab[y][x] == 'p' || map->tab[y][x] == 'c')
	{
		ft_pathfinding(map, x, y + 1);
		ft_pathfinding(map, x + 1, y);
		ft_pathfinding(map, x - 1, y);
		ft_pathfinding(map, x, y - 1);
	}
}
