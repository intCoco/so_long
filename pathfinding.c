/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:37:57 by chuchard          #+#    #+#             */
/*   Updated: 2023/01/12 18:06:53 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// Prints every steps of pathfinding.

void	ft_print_pathfinding(t_map map)
{
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
}

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

// Checks if the map is surrounded by walls and if each character is allowed.

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
			if (pg->map.tab[0][x] != '1' || pg->map.tab[y][pg->map.size.x] != '1'
				|| pg->map.tab[pg->map.size.y][x] != '1' || pg->map.tab[y][0] != '1')
				pg->map.error.walls_check = 1;
			if (pg->map.tab[y][x] != 'P' && pg->map.tab[y][x] != 'C'
				&& pg->map.tab[y][x] != 'E' && pg->map.tab[y][x] != '0'
				&& pg->map.tab[y][x] != '1' && pg->map.tab[y][x] != 'M')
				pg->map.error.char_check = 1;
			x++;
		}
		if (x != pg->map.size.x + 1)
			pg->map.error.rect_check = 1;
		y++;
	}
}

// Counts every collectibles/exits/spawnpoints.

void	ft_count_obj(t_prog *pg)
{
	int	x;
	int	y;

	y = 0;
	while (pg->map.tab[y])
	{
		x = 0;
		while (pg->map.tab[y][x])
		{
			if (pg->map.tab[y][x] == 'P')
				pg->map.obj.p_nb += 1;
			if (pg->map.tab[y][x] == 'E')
				pg->map.obj.e_nb += 1;
			if (pg->map.tab[y][x] == 'C')
				pg->map.obj.c_nb += 1;
			if (pg->map.tab[y][x] == 'M')
				pg->map.obj.m_nb += 1;
			x++;
		}
		y++;
	}
}

// Checks if any collectible or exit is not reachable.
// If after pathfinding any upper c or upper e is left,
// it means that something is not reachable.

void	ft_check_pathfinding(t_prog *pg)
{
	int	x;
	int	y;

	y = 0;
	while (pg->map.tab[y])
	{
		x = 0;
		while (pg->map.tab[y][x])
		{
			if (pg->map.tab[y][x] == 'C')
				pg->map.error.nr_c += 1;
			if (pg->map.tab[y][x] == 'E')
				pg->map.error.nr_e = 1;
			x++;
		}
		y++;
	}
}

// Checks the reachable coordinates of the map.
// If a '0' is reachable, it becomes an 'x' and
// the other chars are lowered if they're reachable.


void	ft_pathfinding(t_prog *pg, int x, int y)
{
	//ft_print_pathfinding(pg->map);
	if (pg->map.tab[y][x] != '1' && pg->map.tab[y][x] != 'x' && pg->map.tab[y][x] != 'c'
		&& pg->map.tab[y][x] != 'e' && pg->map.tab[y][x] != 'p' && pg->map.tab[y][x] != 'f')
	{
		if (pg->map.tab[y][x] == '0')
			pg->map.tab[y][x] = 'x';
		else if (pg->map.tab[y][x] == 'P')
			pg->map.tab[y][x] = 'p';
		else if (pg->map.tab[y][x] == 'C')
			pg->map.tab[y][x] = 'c';
		else if (pg->map.tab[y][x] == 'E')
			pg->map.tab[y][x] = 'e';
		else if (pg->map.tab[y][x] == 'M')
			pg->map.tab[y][x] = 'm';
		ft_pathfinding(pg, x, y + 1);
		ft_pathfinding(pg, x + 1, y);
		ft_pathfinding(pg, x - 1, y);
		ft_pathfinding(pg, x, y - 1);
	}
}

void	ft_set_hz_fences(t_map *map, int x, int y)
{
	int	i;

	if (map->tab2[y][x] != '1' && map->tab2[y][x] != 'v')
		return ;
	i = x;
	while ((map->tab2[y][i] == '1' || map->tab2[y][i] == 'v') && i < map->size.x)
		i++;
	if (i - x > 2)
		while (x < i)
		{
			if (map->tab2[y][x] == 'v')
				map->tab2[y][x] = 'z';
			else
				map->tab2[y][x] = 'h';
			x++;
		}
}

void	ft_set_vt_fences(t_map *map, int x, int y)
{
	int	i;

	if (map->tab2[y][x] != '1' && map->tab2[y][x] != 'h')
		return ;
	i = y;
	while ((map->tab2[i][x] == '1' || map->tab2[i][x] == 'h') && i < map->size.y)
		i++;
	if (i - y > 2)
		while (y < i)
		{
			if (map->tab2[y][x] == 'h')
				map->tab2[y][x] = 'z';
			else
				map->tab2[y][x] = 'v';
			y++;
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
			if (y < map->size.y - 1 && x < map->size.x - 1 && map->tab2[y][x] == '1' && map->tab2[y + 1][x] == '1' && map->tab2[y][x + 1] == '1' && map->tab2[y + 1][x + 1] == '1')
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
			{
				rand = ft_random(3);
				map->tab2[y][x] = rand + 97;
			}
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

int	ft_tabdup(t_map *map)
{
	int		i;

	i = 0;
	map->tab2 = malloc(sizeof(char *) * map->size.y + 1);
	if (!map->tab2)
		return (1);
	while (map->tab[i])
	{
		map->tab2[i] = ft_strdup(map->tab[i]);
		if (!map->tab2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkmapname(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i + 1])
		i++;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i - 3] != '.')
		return (1);
	return (0);
}

// If a map error is detected, prints it on the output.

void	ft_print_error(t_map map)
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

// Checks if there's any kind of map error, if so, calls ft_print_error.

int	ft_check_error(t_prog pg)
{
	if (pg.map.obj.c_nb == 0 || pg.map.obj.e_nb != 1 || pg.map.obj.p_nb != 1 || pg.map.obj.m_nb > 1
		|| pg.map.error.walls_check != 0 || pg.map.error.rect_check != 0
		|| pg.map.error.char_check != 0 || pg.map.error.nr_e != 0
		|| pg.map.error.nr_c != 0 || pg.map.error.fd_er == 1)
		ft_print_error(pg.map);
	else
		return (1);
	return (0);
}

// Frees the map's tab.

int	ft_return(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.size.y + 1)
		free(map.tab[i]);
	free(map.tab);
	return (0);
}

// Calls every functions needed for the map checking and initialization.

t_prog	ft_mapinit(t_prog pg)
{
	pg.pl.d = 2;
	ft_find_p(&pg);
	ft_mapsize(&pg.map);
	ft_check_map(&pg);
	ft_count_obj(&pg);
	pg.ret = ft_tabdup(&pg.map);
	if (pg.pl.pos.x && pg.pl.pos.y)
	{
		ft_pathfinding(&pg, pg.pl.pos.x, pg.pl.pos.y);
		ft_check_pathfinding(&pg);
	}
	if (pg.ret == 0)
		ft_set_misc(&pg.map);
	//ft_block(&pg);
	ft_print_pathfinding(pg.map);
	if (ft_check_error(pg) == 0)
		pg.ret = 1;
	return (pg);
}
