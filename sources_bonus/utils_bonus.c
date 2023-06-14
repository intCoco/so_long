/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:46:52 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:54:09 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

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
	if (im.ref == pg.sp.en[pg.en.count % 2 + 1][pg.en.d].ref && pg.en.mov != 0)
		pg.pl.mov = pg.en.mov;
	if (im.ref == pg.sp.pkb.ref && pg.map.tab[cd.y][cd.x] == 'p')
		pg.pl.mov = pg.pick;
	if (pg.pl.d == 0 && pg.pl.mov)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y - 1) * SQ_L + pg.pl.mov + 244 + ad.y);
	else if (pg.pl.d == 2 && pg.pl.mov)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y + 1) * SQ_L - pg.pl.mov + 244 + ad.y);
	else if (pg.pl.d == 1 && pg.pl.mov)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L - pg.pl.mov + ad.x
			+ 500, (cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	else if (pg.pl.d == 3 && pg.pl.mov)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + pg.pl.mov + ad.x
			+ 500, (cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	else
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

int	ft_close(int merror)
{
	if (merror == 1)
		exit(ft_printf("MALLOC ERROR\n"));
	exit(0);
}
