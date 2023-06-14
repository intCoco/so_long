/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:45:45 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:28:22 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	ingame_inputs(int key, t_prog *pg)
{
	if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'c')				//ramassage
		ft_pick(pg);
	if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'e'
		&& pg->map.obj.c_nb == 0)													//exit si on parle a la fille apres avoir tout ramassé
		ft_close(0);
}

int	ft_input(int key, t_prog *pg)
{
	if (key == 13)																	// definition des holds
		pg->hold[0] = 1;
	else if (key == 0 || key == 1 || key == 2)
		pg->hold[key + 1] = 1;
	if (pg->pl.mov == 0)											//En jeux, si inactif
		ingame_inputs(key, pg);
	if (key == 53)										 							//ferme la console
		ft_close(0);										   						//lance l'anim de fermeture
	return (0);
}

int	ft_release(int key, t_prog *pg)
{
	if (key == 13)
		pg->hold[0] = 0;
	if (key == 0 || key == 1 || key == 2)
		pg->hold[key + 1] = 0;
	return (0);
}
