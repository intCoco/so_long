/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:46:53 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:41:47 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

static void	print_side_walls(t_prog pg)
{
	t_vector	cd;

	cd = ad(0, 0);
	while (++cd.y <= pg.map.size.y + 1 && ++cd.y > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L * 2, -15));
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
	cd = ad(pg.map.size.x + 1, 0);
	while (++cd.y < pg.map.size.y + 1 && ++cd.y > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(SQ_L, -15));
			if (cd.y < pg.map.size.y + 1)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
}

void	print_up_and_side_walls(t_prog pg)
{
	t_vector	cd;

	cd = ad(-2, 0);
	while (++cd.x <= pg.map.size.x + 1 && ++cd.x > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(SQ_L / 2, -48));
			if (cd.x >= 0)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
	print_side_walls(pg);
}

void	ft_print_down_walls(t_prog pg)
{
	t_vector	cd;

	cd.x = 0;
	cd.y = pg.map.size.y + 1;
	while (++cd.x <= pg.map.size.x + 1 && ++cd.x > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			if (cd.x >= 0)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L - SQ_L / 2, 78));
		}
	}
}

void	print_blocks(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == '2')
		print_mov(pg, pg.sp.wall, cd, ad(SQ_L / 2, 15));
	if (pg.map.tab2[cd.y][cd.x] >= 'a' && pg.map.tab2[cd.y][cd.x] <= 'a' + 5)
		print_mov(pg, pg.sp.block[pg.map.tab2[cd.y][cd.x] - 97], cd, ad(0, 0));
}

void	print_fences(t_prog pg, t_vector cd)
{
	if (pg.map.tab2[cd.y][cd.x] == 'h' || pg.map.tab2[cd.y][cd.x] == 'v'
		|| pg.map.tab2[cd.y][cd.x] == 'z')
	{
		print_mov(pg, pg.sp.block[5], cd, ad(0, 0));
		if (pg.map.tab2[cd.y][cd.x + 1] == 'h' || pg.map.tab2[cd.y][cd.x
			+ 1] == 'z')
			print_mov(pg, pg.sp.block[6], cd, ad(SQ_L / 2, 0));
		if (pg.map.tab2[cd.y + 1][cd.x] == 'v' || pg.map.tab2[cd.y
			+ 1][cd.x] == 'z')
			print_mov(pg, pg.sp.block[5], cd, ad(0, SQ_L / 2));
	}
}
