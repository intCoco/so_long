/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:27:06 by chuchard          #+#    #+#             */
/*   Updated: 2025/03/12 15:18:14 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	enemy_behavior(t_prog *pg);
void	player_movements(int key, t_prog *pg);
void	pokemon_behavior(t_prog *pg);
void	player_behavior(t_prog *pg);

void	console_anim(t_prog *pg)
{
	if (pg->begin == 0 || pg->end == 1)												// anim ds
	{
		if (pg->i >= 10)
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
				ft_close(0);
			pg->i = 0;
		}
	}
}

#include <sys/time.h>
long get_time_in_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000; // Retourne le temps en millisecondes
}

// This function is called on every loop/frame.
// It's used to make the animations like the opening one,
// to smoothen the movements and to make timers.

int	ft_update(t_prog *pg)
{
    long current_time = get_time_in_seconds();

    if (current_time - pg->last_time >= 13)
    {
        pg->last_time = current_time;
			pg->frame++;
		if (pg->frame > 50)
			pg->frame = 0;
		if ((pg->begin <= 2 || pg->excl_b > 0) && pg->timer <= 50)						// Fleche des box de dialogue + point d'excl
			pg->timer += 2;
		else
			pg->timer = 0;
		if (pg->begin == 1 && pg->frame % 7 == 0 && pg->i < 23)							// Anim valise
			pg->i++;
		else if (pg->i >= 23 && pg->begin == 2)
			pg->i = 0;

		if (pg->blink > 0 && pg->blink <= 100)
			pg->blink += 2;
		else if (pg->begin == 3 && pg->end == 0)										// In game
		{
			player_behavior(pg);
			enemy_behavior(pg);
			pokemon_behavior(pg);
		}
		console_anim(pg);
		print_game(pg);
    }
	return (0);
}
