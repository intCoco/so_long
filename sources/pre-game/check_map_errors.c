/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/12 17:54:22 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

// Counts every collectibles/exits/spawnpoints, checks if the map is surrounded
// by walls and if each character is allowed.

static void	conditions(t_prog *pg, int x, int y)
{
	if (pg->map.tab[0][x] != '1' || pg->map.tab[y][0] != '1'
		|| pg->map.tab[pg->map.size.y][x] != '1'
		|| pg->map.tab[y][pg->map.size.x] != '1')
		pg->map.error.walls_check = 1;
	if (pg->map.tab[y][x] == 'P')
		pg->map.obj.p_nb += 1;
	else if (pg->map.tab[y][x] == 'E')
		pg->map.obj.e_nb += 1;
	else if (pg->map.tab[y][x] == 'C')
		pg->map.obj.c_nb += 1;
	else if (pg->map.tab[y][x] == 'M')
		pg->map.obj.m_nb += 1;
	else if (pg->map.tab[y][x] != '0' && pg->map.tab[y][x] != '1')
		pg->map.error.char_check = 1;
}

void	ft_check_map(t_prog *pg)
{
	int	x;
	int	y;

	y = 0;
	while (pg->map.tab[y])
	{
		x = 0;
		while (pg->map.tab[y][x])
		{
			conditions(pg, x, y);
			x++;
		}
		if (x != pg->map.size.x + 1)
			pg->map.error.rect_check = 1;
		y++;
	}
}

// Checks if any collectible or exit is not reachable.
// If after pathfinding any upper c or upper e is left,
// it means that something is not reachable.

void	ft_check_pathfinding(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->tab[y])
	{
		x = 0;
		while (map->tab[y][x])
		{
			if (map->tab[y][x] == 'C')
				map->error.nr_c += 1;
			if (map->tab[y][x] == 'E')
				map->error.nr_e = 1;
			x++;
		}
		y++;
	}
}

// If a map error is detected, prints it on the output.

void	ft_print_error_2(t_map map)
{
	if (map.error.rect_check != 0)
		ft_printf("Map is not a rectangle\n");
	else if (map.error.walls_check != 0)
		ft_printf("Invalid surrounding walls\n");
	if (map.error.char_check != 0)
		ft_printf("Map countains invalid chars\n");
	if (map.error.nr_e != 0)
		ft_printf("Exit non-reachable\n");
	if (map.error.nr_c == 1)
		ft_printf("1 collectible non-reachable\n");
	if (map.error.nr_c > 1)
		ft_printf("%d collectibles non-reachable\n", map.error.nr_c);
	if (map.error.fd_er == 1)
		ft_printf("Failed to open the map\n");
}

void	ft_print_error(t_map map)
{
	if (map.obj.c_nb == 0 || map.obj.e_nb != 1 || map.obj.p_nb != 1
		|| map.obj.m_nb > 1 || map.error.nr_e != 0 || map.error.nr_c != 0
		|| map.error.walls_check != 0 || map.error.rect_check != 0
		|| map.error.char_check != 0 || map.error.fd_er == 1)
	{
		ft_printf("Error\n");
		if (map.obj.p_nb < 1)
			ft_printf("No spawnpoint\n");
		if (map.obj.p_nb > 1)
			ft_printf("Several spawnpoints\n");
		if (map.obj.c_nb < 1)
			ft_printf("No collectibles\n");
		if (map.obj.e_nb < 1)
			ft_printf("No exit\n");
		if (map.obj.e_nb > 1)
			ft_printf("Several exits\n");
		if (map.obj.m_nb > 1)
			ft_printf("Several enemies\n");
		ft_print_error_2(map);
	}
}
