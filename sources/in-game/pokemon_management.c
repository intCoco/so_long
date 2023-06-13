/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:39:25 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/13 22:40:41 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

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

void	pokemon_behavior(t_prog *pg)
{
	if (pg->pkm.mov > 0)
		pg->pkm.mov += 3 * (pg->run % 2 + 1);
	else if (pg->pkm.mov >= SQ_L)
		pg->pkm.mov = 0;

	if (pg->pl.count >= 100 && pg->pl.count < 200)
		pg->pkm_ev = 1;
	if (pg->pl.count >= 200 && pg->pl.count < 300)
		pg->pkm_ev = 2;
}
