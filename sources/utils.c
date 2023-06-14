/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:46:52 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:12:29 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	print_im(t_prog pg, t_image im, int x, int y)
{
	mlx_put_image_to_window(pg.mlx, pg.wdw.ref, im.ref, x - (im.size.x / 2),
		y - im.size.y);
}

t_vector	ad(int x, int y)
{
	t_vector	ad;

	ad.x = x;
	ad.y = y;
	return (ad);
}

void	print_mov(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
		(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

int	ft_close(int merror)
{
	if (merror == 1)
		exit(ft_printf("MALLOC ERROR\n"));
	exit(0);
}
