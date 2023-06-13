/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:55 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/13 22:40:36 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

int	ft_move(int key, t_char *chr)
{
	if (key == 2)
		chr->pos.x += 1;
	else if (key == 0)
		chr->pos.x -= 1;
	else if (key == 1)
		chr->pos.y += 1;
	else if (key == 13)
		chr->pos.y -= 1;
	else
		return (0);
	return (1);
}

void	ft_dir_input(int key, t_char *chr)
{
	if (key == 13)
		chr->d = 0;
	else if (key == 2)
		chr->d = 1;
	else if (key == 1)
		chr->d = 2;
	else if (key == 0)
		chr->d = 3;
}

void	ft_fcg_cood(t_char *chr)
{
	chr->fcg.x = chr->pos.x;
	chr->fcg.y = chr->pos.y;
	if (chr->d == 0)
		chr->fcg.y -= 1;
	else if (chr->d == 1)
		chr->fcg.x += 1;
	else if (chr->d == 2)
		chr->fcg.y += 1;
	else if (chr->d == 3)
		chr->fcg.x -= 1;
}
