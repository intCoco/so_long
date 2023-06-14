/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:28 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	ft_find_chars(t_prog *pg)
{
	t_vector	cd;

	cd.y = 0;
	while (pg->map.tab[cd.y])
	{
		cd.x = 0;
		while (pg->map.tab[cd.y][cd.x])
		{
			cd.x++;
			if (pg->map.tab[cd.y][cd.x] == 'P')
				pg->pl.pos = cd;
			if (pg->map.tab[cd.y][cd.x] == 'M')
				pg->en.pos = cd;
			if (pg->map.tab[cd.y][cd.x] == 'E')
				pg->ex.pos = cd;
		}
		cd.y++;
	}
}

// Gives tab's lenght and width.

void	ft_mapsize(t_map *map)
{
	map->size.x = ft_strlen(map->tab[0]) - 1;
	while (map->tab[map->size.y])
		map->size.y++;
	map->size.y--;
}

// Calls every functions needed for the map checking and initialization.

void	ft_set_hz_fences(t_map *map, int x, int y);
void	ft_set_vt_fences(t_map *map, int x, int y);
void	ft_set_tree(t_map *map);
void	ft_set_misc(t_map *map);
void	ft_tabdup(t_map *map);
void	ft_check_map(t_prog *pg);
void	ft_check_pathfinding(t_map *map);
void	ft_print_error(t_map map);
void	ft_pathfinding(t_map *map, int x, int y);
void	ft_find_chars(t_prog *pg);

t_prog	ft_mapinit(t_prog pg)
{
	pg.pl.d = 2;
	pg.en.d = 2;
	pg.pkm.d = 2;
	ft_find_chars(&pg);
	ft_mapsize(&pg.map);
	ft_check_map(&pg);
	ft_tabdup(&pg.map);
	if (pg.pl.pos.x && pg.pl.pos.y)
	{
		ft_pathfinding(&pg.map, pg.pl.pos.x, pg.pl.pos.y);
		ft_check_pathfinding(&pg.map);
	}
	ft_set_misc(&pg.map);
	ft_print_error(pg.map);
	return (pg);
}
