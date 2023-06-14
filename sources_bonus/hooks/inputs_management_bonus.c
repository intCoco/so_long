/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:45:45 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:41:51 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

int	pk_selection(int key, t_prog *pg)
{
	if (pg->select == 0 && pg->begin == 1)											//phase de selection
	{
		if (key == 14)																//selection cette pokbll si on appuie sur e
		{
			pg->pkm_nb = pg->cur_sel;
			pg->select = 1;
		}
		if (key == 0 && pg->cur_sel > 0)											//change de pok si on appuie sur a
			pg->cur_sel -= 1;
		if (key == 2 && pg->cur_sel < 2)											//ou d
			pg->cur_sel += 1;
	}
	else if (pg->select == 1 && pg->begin == 1)										// selection pokemon
	{
		if (key == 13)																//si fleche haut bool = 1
			pg->bol = 1;
		if (key == 1)																//si fleche bas bool = 0
			pg->bol = 0;
		if (key == 14 && pg->bol == 1)												//valide la selection
			pg->begin = 2;
		else if (key == 14 && pg->bol == 0)											//revient en arriere si on choisi "non"
			pg->select = 0;
	}
	return (0);
}

void	ingame_inputs(int key, t_prog *pg)
{
	if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'c')				//ramassage
		ft_pick(pg);
	if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'm')				//parler au mechant
	{
		pg->en.d = pg->pl.d + 2;
		if (pg->pl.d >= 2)
			pg->en.d -= 4;
	}
	if (key == 3)																	//toggle course
		pg->run += 1;
	if (key == 14 && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'e'
		&& pg->map.obj.c_nb == 0)													//exit si on parle a la fille apres avoir tout ramassé
		ft_close(0);
	if (key >= 83 && key <= 85)														//cheat code changement de pok
		pg->pkm_nb = key - 83;
}

int	ft_input(int key, t_prog *pg)
{
	if (pg->begin == 2 && key == 14)												// dialogue debut
		pg->begin = 3;
	pk_selection(key, pg);
	if (key == 13)																	// definition des holds
		pg->hold[0] = 1;
	else if (key == 0 || key == 1 || key == 2)
		pg->hold[key + 1] = 1;
	else if (key == 257)															//hold to run
		pg->run = 1;
	if (pg->pl.mov == 0 && pg->begin == 3 && pg->blink == 0 && pg->excl_b == 0)		//En jeux, si inactif
		ingame_inputs(key, pg);
	if (key == 14 && pg->excl_b == 3 && pg->blink == 0)								//passe le dialogue du mechant
		pg->blink = 1;										 						//lance le timer et le clignotement avant l'anim de combat
	if (key == 53)										 							//ferme la console
		pg->end = 1;										   						//lance l'anim de fermeture
	return (0);
}

int	ft_release(int key, t_prog *pg)
{
	if (key == 13)
		pg->hold[0] = 0;
	if (key == 0 || key == 1 || key == 2)
		pg->hold[key + 1] = 0;
	else if (key == 257)
		pg->run = 0;
	return (0);
}
