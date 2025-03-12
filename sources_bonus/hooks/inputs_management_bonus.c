/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:45:45 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/13 07:08:06 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

int	pk_selection(int key, t_prog *pg)
{
	if (pg->select == 0 && pg->begin == 1)											//phase de selection
	{
		if (key == KEY_E)																//selection cette pokbll si on appuie sur e
		{
			pg->pkm_nb = pg->cur_sel;
			pg->select = 1;
		}
		if (key == KEY_A && pg->cur_sel > 0)											//change de pok si on appuie sur a
			pg->cur_sel -= 1;
		if (key == KEY_D && pg->cur_sel < 2)											//ou d
			pg->cur_sel += 1;
	}
	else if (pg->select == 1 && pg->begin == 1)										// selection pokemon
	{
		if (key == KEY_W)																//si fleche haut bool = 1
			pg->bol = 1;
		if (key == KEY_S)																//si fleche bas bool = 0
			pg->bol = 0;
		if (key == KEY_E && pg->bol == 1)												//valide la selection
			pg->begin = 2;
		else if (key == KEY_E && pg->bol == 0)											//revient en arriere si on choisi "non"
			pg->select = 0;
	}
	return (0);
}

void	ingame_inputs(int key, t_prog *pg)
{
	if (key == KEY_E && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'c')				//ramassage
		ft_pick(pg);
	if (key == KEY_E && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'm')				//parler au mechant
	{
		pg->en.d = pg->pl.d + 2;
		if (pg->pl.d >= 2)
			pg->en.d -= 4;
	}
	if (key == KEY_F)																	//toggle course
		pg->run += 1;
	if (key == KEY_E && pg->map.tab[pg->pl.fcg.y][pg->pl.fcg.x] == 'e'
		&& pg->map.obj.c_nb == 0)													//exit si on parle a la fille apres avoir tout ramassé
		ft_close(0);
	if (key == KEY_1)
		pg->pkm_nb = 0;
	if (key == KEY_2)
		pg->pkm_nb = 1;
	if (key == KEY_3)
		pg->pkm_nb = 2;
}


int	ft_input(int key, t_prog *pg)
{
	printf("%i\n", key);
	if (pg->begin == 2 && key == KEY_E)												// dialogue debut
		pg->begin = 3;
	pk_selection(key, pg);
	if (key == KEY_W)																	// definition des holds
		pg->hold[0] = 1;
	if (key == KEY_A)																	// definition des holds
		pg->hold[1] = 1;
	if (key == KEY_S)																	// definition des holds
		pg->hold[2] = 1;
	if (key == KEY_D)																	// definition des holds
		pg->hold[3] = 1;
	else if (key == KEY_MAJ)															//hold to run
		pg->run = 1;
	if (pg->pl.mov == 0 && pg->begin == 3 && pg->blink == 0 && pg->excl_b == 0)		//En jeux, si inactif
		ingame_inputs(key, pg);
	if (key == KEY_E && pg->excl_b == 3 && pg->blink == 0)								//passe le dialogue du mechant
		pg->blink = 1;										 						//lance le timer et le clignotement avant l'anim de combat
	if (key == KEY_ESC)										 							//ferme la console
		pg->end = 1;										   						//lance l'anim de fermeture
	return (0);
}

int	ft_release(int key, t_prog *pg)
{
	if (key == KEY_W)
		pg->hold[0] = 0;
	if (key == KEY_A)																	// definition des holds
		pg->hold[1] = 0;
	if (key == KEY_S)																	// definition des holds
		pg->hold[2] = 0;
	if (key == KEY_D)																	// definition des holds
		pg->hold[3] = 0;
	else if (key == KEY_MAJ)
		pg->run = 0;
	return (0);
}
