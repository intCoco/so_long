/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:45:33 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:41:42 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

static void	print_collec(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == 'c')
		print_mov(pg, pg.sp.pkb, cd, ad(0, 0));
	else if (pg.map.tab[cd.y][cd.x] == 'p' && pg.pick >= 1 && pg.pick <= 30)
		print_mov(pg, pg.sp.pkb, cd, ad(0, -ft_sqrt(pg.pick * 2)));
}

static void	print_ground(t_prog pg)
{
	t_vector	cd;

	cd.y = pg.pl.pos.y - 7;
	while (cd.y < pg.pl.pos.y + 8)
	{
		cd.x = pg.pl.pos.x - 7;
		while (cd.x < pg.pl.pos.x + 8)
		{
			if (cd.y >= -1 && cd.x >= -1 && cd.y <= pg.map.size.y + 1
				&& cd.x <= pg.map.size.x + 1)
				print_mov(pg, pg.sp.ground, cd, ad(0, 11));
			if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg.map.size.y
				&& cd.x <= pg.map.size.x)
				if (pg.map.tab2[cd.y][cd.x] >= '2'
					&& pg.map.tab2[cd.y][cd.x] <= '7')
					print_mov(pg, pg.sp.flower[pg.map.tab2[cd.y][cd.x] - 50],
						cd, ad(0, 5));
			cd.x++;
		}
		cd.y++;
	}
}

static void	print_darkness(t_prog pg)
{
	t_vector	cd;

	cd.x = -4;
	cd.y = 0;
	while (++cd.x <= pg.map.size.x + 2 && ++cd.x > -10)
		print_mov(pg, pg.sp.dk[0], cd, ad(-SQ_L / 2, 0));
	cd.x = pg.map.size.x + 1;
	cd.y = -4;
	while (++cd.y <= pg.map.size.y + 2 && ++cd.y > -10)
		print_mov(pg, pg.sp.dk[1], cd, ad(SQ_L / 2 + 10, -32));
	cd.x = -2;
	cd.y = -2;
	while (++cd.y <= pg.map.size.y + 2 && ++cd.y > -10)
		print_mov(pg, pg.sp.dk[3], cd, ad(10, -32));
	cd.x = -4;
	cd.y = pg.map.size.y + 1;
	while (++cd.x <= pg.map.size.x + 2 && ++cd.x > -10)
		print_mov(pg, pg.sp.dk[2], cd, ad(-SQ_L / 2, 70));
}

void	print_up_and_side_walls(t_prog pg);
void	print_fences(t_prog pg, t_vector cd);
void	print_blocks(t_prog pg, t_vector cd);
void	print_excl(t_prog pg);
void	print_player(t_prog pg);
void	print_chars(t_prog pg, t_vector cd);
void	ft_print_down_walls(t_prog pg);

void	print_map(t_prog pg)
{
	t_vector	cd;

	print_ground(pg);
	print_up_and_side_walls(pg);
	cd.y = pg.pl.pos.y - 8;
	while (++cd.y < pg.pl.pos.y + 8)
	{
		cd.x = pg.pl.pos.x - 8;
		while (++cd.x < pg.pl.pos.x + 8)
		{
			if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg.map.size.y
				&& cd.x <= pg.map.size.x)
			{
				print_collec(pg, cd);
				print_chars(pg, cd);
				print_fences(pg, cd);
				print_blocks(pg, cd);
				print_excl(pg);
			}
		}
		if (cd.y == pg.pl.pos.y)
			print_player(pg);
	}
	ft_print_down_walls(pg);
	print_darkness(pg);
}
