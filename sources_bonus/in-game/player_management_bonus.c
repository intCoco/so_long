/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:55:51 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/13 07:23:54 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	ft_pick(t_prog *pg)
{
	pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] = 'x';
	pg->pick = 1;
	pg->map.obj.c_nb -= 1;
}

int	ft_input_pkm(t_prog *pg);

void	player_movements(int key, t_prog *pg)
{
	if (pg->pl.mov == 0 && pg->begin == 3 && pg->blink == 0 && pg->excl_b == 0)
	{
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'x';
		if (pg->pkm.count == 0)
			pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = '.';
		if (pg->pl.mov == 0 && pg->pick == 0)
		{
			ft_dir_input(key, &pg->pl);
			ft_fcg_cood(&pg->pl);
			if ((pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'x'
				|| pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == '.'))
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
		}
		ft_fcg_cood(&pg->pl);
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'p';
	}
}

void	player_behavior(t_prog *pg)
{
	if (pg->pl.mov > 0 && pg->run % 2 == 0)
		pg->pl.mov += 3;
	else if (pg->pl.mov > 0 && pg->run % 2 == 1)
		pg->pl.mov += 6;
	if (pg->pl.mov >= SQ_L)
		pg->pl.mov = 0;
	if (pg->hold[0] == 1 && pg->pl.mov == 0)
		player_movements(13, pg);
	else if (pg->hold[1] == 1 && pg->pl.mov == 0)
		player_movements(0, pg);
	else if (pg->hold[2] == 1 && pg->pl.mov == 0)
		player_movements(1, pg);
	else if (pg->hold[3] == 1 && pg->pl.mov == 0)
		player_movements(2, pg);
	if (pg->pick != 0)
		pg->pick += 4;
	if (pg->pick >= SQ_L)
		pg->pick = 0;
}
