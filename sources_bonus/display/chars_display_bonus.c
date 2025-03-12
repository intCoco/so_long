/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:30:55 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/13 05:29:32 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	rot_exit(t_prog *pg);
void	print_mov_pkm(t_prog pg, t_image im, t_vector cd, t_vector ad);

void	print_chars(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == 'e')
	{
		rot_exit(&pg);
		if (pg.map.obj.c_nb != 0)
			print_mov(pg, pg.sp.fpl_sav, cd, ad(0, 0));
		if (pg.map.obj.c_nb == 0)
			print_mov(pg, pg.sp.fpl[pg.ex.d], cd, ad(0, 0));
	}
	else if (pg.map.tab[cd.y][cd.x] == 'm')
	{
		if (pg.en.mov == 0)
			print_mov(pg, pg.sp.en[0][pg.en.d], cd, ad(0, 0));
		else if (pg.en.mov != 0)
			print_mov(pg, pg.sp.en[pg.en.count % 2 + 1][pg.en.d], cd, ad(0, 0));
	}
	else if (pg.map.tab[cd.y][cd.x] == '.')
	{
		if (pg.pkm.count == 0)
			print_mov(pg, pg.sp.pkm[pg.pkm_nb][pg.pkm_ev][pg.pkm.count
				% 2][pg.pkm.d], cd, ad(0, 0));
		else
			print_mov_pkm(pg, pg.sp.pkm[pg.pkm_nb][pg.pkm_ev][pg.pkm.count
				% 2][pg.pkm.d], cd, ad(0, 0));
	}
}

void	print_player(t_prog pg)
{
	if (pg.pick >= 1)
		print_im(pg, pg.sp.pc[pg.pl.d], 500, 244);
	if (pg.pl.mov == 0 && pg.pick == 0)
		print_im(pg, pg.sp.pl[0][0][pg.pl.d], 500, 244);
	if (pg.pl.mov != 0)
		print_im(pg, pg.sp.pl[pg.run % 2][pg.pl.count % 2 + 1][pg.pl.d],
			500, 244);
}
