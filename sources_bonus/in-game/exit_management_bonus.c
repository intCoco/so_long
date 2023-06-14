/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:49:38 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:13 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	rot_exit(t_prog *pg)
{
	t_vector	cd_r;

	cd_r.x = ft_abs(pg->pl.pos.x - pg->ex.pos.x);
	cd_r.y = ft_abs(pg->pl.pos.y - pg->ex.pos.y);
	if (pg->map.obj.c_nb == 0)
	{
		if (cd_r.x > cd_r.y)
		{
			if (pg->pl.pos.x < pg->ex.pos.x)
				pg->ex.d = 3;
			else if (pg->pl.pos.x > pg->ex.pos.x)
				pg->ex.d = 1;
		}
		else if (cd_r.x <= cd_r.y)
		{
			if (pg->pl.pos.y < pg->ex.pos.y)
				pg->ex.d = 0;
			else if (pg->pl.pos.y > pg->ex.pos.y)
				pg->ex.d = 2;
		}
	}
}
