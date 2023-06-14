/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:48:45 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:10 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	en_mov(t_prog *pg, int x, int y)
{
	pg->en.pos.x += x;
	pg->en.pos.y += y;
	pg->en.mov = 1;
	pg->en.count += 1;
}

void	ft_interac_en(t_prog *pg, t_vector *cd)
{
	if (pg->en.mov == 0 && pg->timer == 0)
	{
		if (pg->excl_b == 1)
		{
			pg->pl.d = pg->en.d + 2;
			if (pg->en.d >= 2)
				pg->pl.d -= 4;
			pg->excl_b = 2;
		}
		if (pg->excl_b == 2 && pg->en.mov == 0)
		{
			pg->map.tab[pg->en.pos.y][pg->en.pos.x] = 'x';
			if (pg->en.d == 0 && pg->map.tab[cd->y - 1][cd->x] != 'p')
				en_mov(pg, 0, -1);
			else if (pg->en.d == 1 && pg->map.tab[cd->y][cd->x + 1] != 'p')
				en_mov(pg, 1, 0);
			else if (pg->en.d == 2 && pg->map.tab[cd->y + 1][cd->x] != 'p')
				en_mov(pg, 0, 1);
			else if (pg->en.d == 3 && pg->map.tab[cd->y][cd->x - 1] != 'p')
				en_mov(pg, -1, 0);
			else
				pg->excl_b = 3;
			pg->map.tab[pg->en.pos.y][pg->en.pos.x] = 'm';
		}
	}
}

void	ft_encheck(t_prog *pg)
{
	t_vector	cd;

	cd.x = pg->en.pos.x;
	cd.y = pg->en.pos.y;
	if (pg->en.d == 0)
		while ((pg->map.tab[cd.y][cd.x] == 'm'
			|| pg->map.tab[cd.y][cd.x] == 'x') && cd.y > pg->en.pos.y - 3)
			cd.y--;
	else if (pg->en.d == 2)
		while ((pg->map.tab[cd.y][cd.x] == 'm'
			|| pg->map.tab[cd.y][cd.x] == 'x') && cd.y < pg->en.pos.y + 3)
			cd.y++;
	else if (pg->en.d == 1)
		while ((pg->map.tab[cd.y][cd.x] == 'm'
			|| pg->map.tab[cd.y][cd.x] == 'x') && cd.x < pg->en.pos.x + 3)
			cd.x++;
	else if (pg->en.d == 3)
		while ((pg->map.tab[cd.y][cd.x] == 'm'
			|| pg->map.tab[cd.y][cd.x] == 'x') && cd.x > pg->en.pos.x - 3)
			cd.x--;
	if (pg->map.tab[cd.y][cd.x] == 'p' && pg->excl_b == 0 && pg->pl.mov == 0)
		pg->excl_b = 1;
	else
		ft_interac_en(pg, &pg->en.pos);
}

void	enemy_behavior(t_prog *pg)
{
	if (pg->frame == 50 && pg->excl_b == 0)
	{
		pg->en.d += 1;
		ft_fcg_cood(&pg->en);
		if (pg->map.tab[pg->en.fcg.y][pg->en.fcg.x] == '1')
			pg->en.d += 1;
	}
	if (pg->en.mov == 0 && pg->map.obj.m_nb != 0)
		ft_encheck(pg);
	if (pg->en.d == 4)
		pg->en.d = 0;
	if (pg->en.mov != 0 && pg->en.mov < SQ_L)
		pg->en.mov += 2;
	else if (pg->en.mov >= SQ_L)
		pg->en.mov = 0;
}
