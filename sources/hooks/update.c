/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:27:06 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:39:29 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

// This function is called on every loop/frame.
// It's used to make the animations like the opening one,
// to smoothen the movements and to make timers.

int	ft_update(t_prog *pg)
{
	player_behavior(pg);
	print_game(pg);
	return (0);
}
