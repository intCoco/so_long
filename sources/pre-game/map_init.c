/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:40:14 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

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

t_prog	ft_mapinit(t_prog pg)
{
	pg.pl.d = 2;
	pg.ex.d = 2;
	ft_find_chars(&pg);
	ft_mapsize(&pg.map);
	ft_check_map(&pg);
	if (pg.pl.pos.x && pg.pl.pos.y)
	{
		ft_pathfinding(&pg.map, pg.pl.pos.x, pg.pl.pos.y);
		ft_check_pathfinding(&pg.map);
	}
	ft_print_error(pg.map);
	return (pg);
}
