/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/12 22:44:04 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

// Finds player's coordinates.

void	ft_find_p(t_prog *pg)
{
	pg->pl.pos.y = 0;
	while (pg->map.tab[pg->pl.pos.y])
	{
		pg->pl.pos.x = 0;
		while (pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] != 'P'
			&& pg->map.tab[pg->pl.pos.y][pg->pl.pos.x])
			pg->pl.pos.x++;
		if (pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] == 'P')
			return ;
		pg->pl.pos.y++;
	}
	pg->pl.pos.x = 0;
	pg->pl.pos.y = 0;
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

t_prog	ft_mapinit(t_prog pg)
{
	pg.pl.d = 2;
	pg.en.d = 2;
	pg.pkm.d = 2;
	ft_find_p(&pg);
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
