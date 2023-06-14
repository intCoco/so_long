/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:40:47 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 16:47:30 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	print_watch(t_prog pg)
{
	char	*str;
	int		i;

	i = 4;
	mlx_string_put(pg.mlx, pg.wdw.ref, 465, 675, 0, ft_itoa(pg.pl.count));
	print_im(pg, pg.sp.bg, 500, 918);
	str = malloc(5);
	while (i >= 0)
	{
		str[i--] = (pg.pl.count % 10) + '0';
		pg.pl.count /= 10;
	}
	i = 0;
	while (i < 5)
	{
		print_im(pg, pg.sp.nb[str[i] - 48], (i - 3) * 29 + 500, 712);
		i++;
	}
	free(str);
}

void	print_select_menu(t_prog pg);
void	print_map(t_prog pg);
void	print_npc_interactions(t_prog pg);
void	ft_fight_anim(t_prog *pg);

void	print_game(t_prog *pg)
{
	mlx_clear_window(pg->mlx, pg->wdw.ref);
	if (pg->begin != 0 && pg->end == 0)
	{
		if (pg->begin == 1)
			print_select_menu(*pg);
		else if (pg->split == 0 && !((pg->blink > 25 && pg->blink < 50)
				|| (pg->blink > 75 && pg->blink < 100)) && pg->begin > 1)
			print_map(*pg);
		print_npc_interactions(*pg);
		print_im(*pg, pg->sp.intro[0], 500, 1000);
		if (pg->begin > 1)
			print_watch(*pg);
		if (pg->excl_b == 3 && pg->blink >= 100)
			ft_fight_anim(pg);
	}
	else if (pg->end == 0)
		print_im(*pg, pg->sp.intro[6 - pg->i], 500, 1000);
	else
		print_im(*pg, pg->sp.intro[pg->i], 500, 1000);
}
