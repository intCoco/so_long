/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/13 22:07:52 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	ft_set_hz_fences(t_map *map, int x, int y)
{
	int	i;

	if (map->tab2[y][x] != '1' && map->tab2[y][x] != 'v')
		return ;
	i = x;
	while ((map->tab2[y][i] == '1' || map->tab2[y][i] == 'v')
		&& i < map->size.x)
		i++;
	if (i - x > 2)
	{
		while (x < i)
		{
			if (map->tab2[y][x] == 'v')
				map->tab2[y][x] = 'z';
			else
				map->tab2[y][x] = 'h';
			x++;
		}
	}
}

void	ft_set_vt_fences(t_map *map, int x, int y)
{
	int	i;

	if (map->tab2[y][x] != '1' && map->tab2[y][x] != 'h')
		return ;
	i = y;
	while ((map->tab2[i][x] == '1' || map->tab2[i][x] == 'h')
		&& i < map->size.y)
		i++;
	if (i - y > 2)
	{
		while (y < i)
		{
			if (map->tab2[y][x] == 'h')
				map->tab2[y][x] = 'z';
			else
				map->tab2[y][x] = 'v';
			y++;
		}
	}
}

void	ft_set_tree(t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->size.y)
	{
		x = 1;
		while (x < map->size.x)
		{
			if (y < map->size.y - 1 && x < map->size.x - 1
				&& map->tab2[y][x] == '1' && map->tab2[y + 1][x + 1] == '1'
				&& map->tab2[y][x + 1] == '1' && map->tab2[y + 1][x] == '1')
			{
				map->tab[y + 1][x] = '2';
				map->tab2[y + 1][x] = '0';
				map->tab2[y][x] = '0';
				map->tab2[y][x + 1] = '0';
				map->tab2[y + 1][x + 1] = '0';
			}
			x++;
		}
		y++;
	}
}

void	ft_set_misc(t_map *map)
{
	int	x;
	int	y;
	int	rand;

	y = 1;
	ft_set_tree(map);
	while (y < map->size.y)
	{
		x = 1;
		while (x < map->size.x)
		{
			ft_set_hz_fences(map, x, y);
			ft_set_vt_fences(map, x, y);
			if (y < map->size.y && x < map->size.x && map->tab2[y][x] == '1')
				map->tab2[y][x] = ft_random(3) + 97;
			else if (map->tab2[y][x] == '0')
			{
				rand = ft_random(25);
				if (rand >= 0 && rand <= 6)
					map->tab2[y][x] = rand + 50;
			}
			x++;
		}
		y++;
	}
}

void	ft_tabdup(t_map *map)
{
	int		i;

	i = 0;
	map->tab2 = malloc(sizeof(char *) * map->size.y + 1);
	if (!map->tab2)
		ft_close(1);
	while (map->tab[i])
	{
		map->tab2[i] = ft_strdup(map->tab[i]);
		if (!map->tab2[i])
			ft_close(1);
		i++;
	}
}
