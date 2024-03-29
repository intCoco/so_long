/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:55:51 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:39:51 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	ft_pick(t_prog *pg)
{
	pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] = 'x';
	pg->map.obj.c_nb -= 1;
}

void	player_movements(int key, t_prog *pg)
{
	if (pg->pl.mov == 0)
	{
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'x';
		if (pg->pl.mov == 0)
		{
			ft_dir_input(key, &pg->pl);
			ft_fcg_cood(&pg->pl);
			if (pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'x')
			{
				if (ft_move(key, &pg->pl) == 1)
				{
					pg->pl.mov = 1;
					pg->pl.count++;
					ft_printf("Steps count = %d\n", pg->pl.count);
				}
			}
		}
		ft_fcg_cood(&pg->pl);
		pg->map.tab[pg->pl.pos.y][pg->pl.pos.x] = 'p';
	}
}

void	player_behavior(t_prog *pg)
{
	if (pg->pl.mov > 0)
		pg->pl.mov += 3;
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
}
