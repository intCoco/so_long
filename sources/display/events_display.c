/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:40:55 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/13 23:41:42 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	print_select_menu(t_prog pg)
{
	print_im(pg, pg.sp.pkm_anim[pg.i], 500, 410);
	if (pg.i == 23 && pg.select == 0)
	{
		print_im(pg, pg.sp.crs[pg.cur_sel], 500, 400 + pg.timer / 3);
		print_im(pg, pg.sp.arw, 681, 406 + pg.timer / 10);
	}
	if (pg.i == 23 && pg.select == 1)
	{
		print_im(pg, pg.sp.pkm_sel[pg.pkm_nb], 500, 408);
		print_im(pg, pg.sp.bol_crs, 607, 286 - pg.bol * 28);
	}
}

void	ft_fight_anim(t_prog *pg)
{
	if (pg->frame == 2 && pg->i < 10)
		pg->i += 1;
	else if (pg->frame >= 5)
		pg->frame = 0;
	if (pg->i == 10 && pg->split == 0)
		pg->split = 1;
	if (pg->split != 0 && pg->split < 500)
		pg->split += 10;
	if (pg->split >= 500)
	{
		pg->end = 1;
		pg->i = 0;
	}
}

static void	print_fight_anim(t_prog pg)
{
	if (pg.i <= 9)
		print_im(pg, pg.sp.anim[pg.i], 500, 240 + pg.sp.anim[pg.i].size.y / 2);
	else if (pg.i == 10)
	{
		print_im(pg, pg.sp.anim2[0], 500 - pg.split,
			240 + pg.sp.anim2[0].size.y / 2);
		print_im(pg, pg.sp.anim2[1], 500 + pg.split,
			240 + pg.sp.anim2[1].size.y / 2);
	}
}

void	print_npc_interactions(t_prog pg)
{
	if (pg.begin == 2)
	{
		print_im(pg, pg.sp.fpl_dia, 360, 340);
		print_im(pg, pg.sp.dia_box[1], 500, 410);
		print_im(pg, pg.sp.arw, 710, 405 + pg.timer / 10);
	}
	if (pg.excl_b == 3 && pg.blink == 0)
	{
		print_im(pg, pg.sp.dia_box[0], 500, 410);
		print_im(pg, pg.sp.arw, 710, 405 + pg.timer / 10);
	}
	if (pg.excl_b == 3 && pg.blink >= 100)
		print_fight_anim(pg);
}

void	print_excl(t_prog pg)
{
	if (pg.timer != 0 && pg.timer < 15 && pg.excl_b == 1)
		print_im(pg, pg.sp.excl, (pg.en.pos.x - pg.pl.pos.x) * SQ_L + 500,
			(pg.en.pos.y - pg.pl.pos.y - 1) * SQ_L + 270 - pg.timer);
	if (pg.timer != 0 && pg.timer >= 15 && pg.excl_b == 1)
		print_im(pg, pg.sp.excl, (pg.en.pos.x - pg.pl.pos.x) * SQ_L + 500,
			(pg.en.pos.y - pg.pl.pos.y - 1) * SQ_L + 270);
}
