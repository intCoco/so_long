/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:45:33 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:21 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

static void	print_ground(t_prog pg)
{
	t_vector	cd;

	cd.y = pg.pl.pos.y - 7;
	while (cd.y < pg.pl.pos.y + 8)
	{
		cd.x = pg.pl.pos.x - 7;
		while (cd.x < pg.pl.pos.x + 8)
		{
			if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg.map.size.y
				&& cd.x <= pg.map.size.x)
				print_mov(pg, pg.sp.ground, cd, ad(0, 11));
			cd.x++;
		}
		cd.y++;
	}
}

void	print_game(t_prog *pg)
{
	t_vector	cd;

	mlx_clear_window(pg->mlx, pg->wdw.ref);
	print_ground(*pg);
	cd.y = pg->pl.pos.y - 8;
	while (++cd.y < pg->pl.pos.y + 8)
	{
		cd.x = pg->pl.pos.x - 8;
		while (++cd.x < pg->pl.pos.x + 8)
		{
			if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg->map.size.y
				&& cd.x <= pg->map.size.x)
			{
				if (pg->map.tab[cd.y][cd.x] == 'c')
					print_mov(*pg, pg->sp.pkb, cd, ad(0, 0));
				if (pg->map.tab[cd.y][cd.x] == 'e')
					print_mov(*pg, pg->sp.fpl, cd, ad(0, 0));
				if (pg->map.tab[cd.y][cd.x] == 'p')
					print_im(*pg, pg->sp.pl[pg->pl.d], 500, 244);
				if (pg->map.tab[cd.y][cd.x] == '1')
					print_mov(*pg, pg->sp.wall, cd, ad(0, 0));
			}
		}
	}
	print_im(*pg, pg->sp.intro, 500, 1000);
}
