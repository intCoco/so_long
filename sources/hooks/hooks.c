/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:27:06 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/06 19:52:41 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

void	ft_fcg_cood(t_char *chr)
{
	chr->fcg.x = chr->pos.x;
	chr->fcg.y = chr->pos.y;
	if (chr->d == 0)
		chr->fcg.y -= 1;
	else if (chr->d == 1)
		chr->fcg.x += 1;
	else if (chr->d == 2)
		chr->fcg.y += 1;
	else if (chr->d == 3)
		chr->fcg.x -= 1;
}

void	ft_dir_input(int key, t_char *chr)
{
	if (key == 13)
		chr->d = 0;
	else if (key == 2)
		chr->d = 1;
	else if (key == 1)
		chr->d = 2;
	else if (key == 0)
		chr->d = 3;
}

void	ft_pick(t_prog *pg)
{
	pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] = 'x';
	pg->pick = 1;
	pg->map.obj.c_nb -= 1;
}

int	ft_move(int key, t_char *chr)
{
	if (key == 2)
		chr->pos.x += 1;
	else if (key == 0)
		chr->pos.x -= 1;
	else if (key == 1)
		chr->pos.y += 1;
	else if (key == 13)
		chr->pos.y -= 1;
	else
		return (0);
	return (1);
}

int	ft_input_pkm(t_prog *pg)
{
	if (pg->pl.count == 0)
		pg->pkm.pos = pg->pl.pos;
	else if (pg->lkey == 0 || pg->lkey == 1 || pg->lkey == 2 || pg->lkey == 13)
	{
		pg->map.tab[pg->pkm.pos.y][pg->pkm.pos.x] = 'x';
		ft_dir_input(pg->lkey, &pg->pkm);
		ft_fcg_cood(&pg->pkm);
		if (ft_move(pg->lkey, &pg->pkm) == 1)
		{
			pg->pkm.mov = 1;
			pg->pkm.count++;
		}
		pg->map.tab[pg->pkm.pos.y][pg->pkm.pos.x] = '.';
	}
	return (0);
}

// Performs the necessary actions when a particular key is pressed

int	ft_input(int key, t_prog *pg)
{
	int		y;
	int		x;

	if (pg->pl.mov == 0 && pg->begin == 3 && pg->tanim == 0 && pg->excl_b == 0)
	{
		x = pg->pl.fcg.x;
		y = pg->pl.fcg.y;
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'x';
		if (pg->pl.mov == 0 && pg->pick == 0)
			ft_dir_input(key, &pg->pl);
		ft_fcg_cood(&pg->pl);
		if (pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] != '1' && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] != 'c' && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] != 'e' && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] != 'm' && pg->pl.mov == 0 && pg->pick == 0 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] != '2')
		{
			if (key == 0 || key == 1 || key == 2 || key == 13)
				ft_input_pkm(pg);
			if (ft_move(key, &pg->pl) == 1)
			{
				pg->pl.mov = 1;
				pg->pl.count++;
				pg->lkey = key;
			}
		}
		if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'c')
			ft_pick(pg);
		if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'm')
		{
			pg->en.d = pg->pl.d + 2;
			if (pg->pl.d >= 2)
				pg->en.d -= 4;
		}
		if (key == 3)
			pg->run += 1;
		if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'e' && pg->map.obj.c_nb == 0)
			ft_close(pg, NULL);
		if (key >= 83 && key <= 85)
			pg->pkm_nb = key - 83;
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'p';
	}
	if (key == 14 && pg->excl_b == 3 && pg->tanim == 0)
		pg->tanim = 1;
	if (pg->begin == 2 && key == 14)
		pg->begin = 3;
	if (pg->select == 1 && pg->begin == 1)
	{
		if (key == 13 && pg->begin == 1)
			pg->bol = 1;
		if (key == 1 && pg->begin == 1)
			pg->bol = 0;
		if (key == 14 && pg->bol == 1)
		{
			pg->begin = 2;
			pg->i = 0;
		}
		if (key == 14 && pg->bol == 0)
			pg->select = 2;
	}
	if (pg->select == 0 && pg->begin == 1)
	{
		if (key == 0 && pg->cur_sel > 0)
			pg->cur_sel -= 1;
		if (key == 2 && pg->cur_sel < 2)
			pg->cur_sel += 1;
		if (key == 14)
		{
			pg->pkm_nb = pg->cur_sel;
			pg->select = 1;
		}
	}
	if (pg->select == 2)
		pg->select = 0;
	//printf("select = %d\nbol = %d\n", pg->select, pg->bol);
	//printf("select = %d\nbol = %d\n", pg->select, pg->bol);
	if (key == 53)
		pg->end = 1;
	//ft_print_pathfinding(pg->map);
	//printf("Key pressed -> %d\n", key);
	return (0);
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

// This function is called on every loop/frame.
// It's used to make the animations like the opening one,
// to smoothen the movements and to make timers. 

int	ft_update(t_prog *pg)
{
	//printf("begin = %d\n", pg->begin);
	pg->frame++;
	// Fleche de la box
	if (pg->begin == 2 || (pg->excl_b == 3 && pg->tanim == 0) || pg->i == 23)
		pg->timer2 += 2;
	else
		pg->timer2 = 0;
	if (pg->timer2 >= 50)
		pg->timer2 = 0;
	
	// Anim choix pokemon
	if (pg->begin == 1 && pg->frame % 5 == 0 && pg->i < 23)
		pg->i++;

	// In game
	else if (pg->begin == 3 && pg->end == 0)
	{
		if (pg->tanim > 0 && pg->tanim <= 100)
			pg->tanim += 2;
		if (pg->excl_b == 3 && pg->tanim >= 100)
			ft_fight_anim(pg);
		else
		{
			if (pg->frame > 50)
				pg->frame = 0;
			if (pg->pl.mov > 0 && pg->run % 2 == 0)
				pg->pl.mov += 3;
			else if (pg->pl.mov > 0 && pg->run % 2 == 1)
				pg->pl.mov += 6;
			if (pg->pl.mov >= SQ_L)
				pg->pl.mov = 0;
			if (pg->timer > 0)
				pg->timer += 2;
			if (pg->timer >= 50)
				pg->timer = 0;
			if (pg->pick != 0)
				pg->pick += 4;
			if (pg->pick >= SQ_L)
				pg->pick = 0;
			if (pg->frame == 50 && pg->excl_b == 0)
			{
				pg->en.d += 1;
				ft_fcg_cood(&pg->en);
				if (pg->map.tab[pg->en.fcg.y][pg->en.fcg.x] == '1')
					pg->en.d += 1;
			}
			if (pg->en.mov == 0 && pg->map.obj.m_nb != 0)
				*pg = ft_encheck(*pg);
			if (pg->en.d == 4)
				pg->en.d = 0;
			if (pg->en.mov != 0 && pg->en.mov < SQ_L)
				pg->en.mov += 2;
			else if (pg->en.mov >= SQ_L)
				pg->en.mov = 0;
			if (pg->pkm.mov > 0 && pg->run % 2 == 0)
				pg->pkm.mov += 3;
			else if (pg->pkm.mov > 0 && pg->run % 2 == 1)
				pg->pkm.mov += 6;
			if (pg->pkm.mov >= SQ_L)
				pg->pkm.mov = 0;
			
			if (pg->pl.count >= 100 && pg->pl.count < 200)
				pg->pkm_ev = 1;
			if (pg->pl.count >= 200 && pg->pl.count < 300)
				pg->pkm_ev = 2;
		}
	}
	if (pg->begin == 0 || pg->end == 1)
	{
		if (pg->i > 10)
			pg->i = 0;
		if (pg->frame == 10 && pg->i < 6 && (pg->begin == 0 || pg->end == 1))
			pg->i += 1;
		else if (pg->frame >= 10 && pg->i < 6)
			pg->frame = 0;
		if (pg->i == 6)
		{
			if (pg->begin == 0)
				pg->begin = 1;
			else
				ft_close(pg, NULL);
			pg->i = 0;
		}
	}
	print_game(*pg);
	return (0);
}
