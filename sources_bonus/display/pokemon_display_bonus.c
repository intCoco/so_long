/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_display_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:35:37 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:41:44 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

static void	print_mov_pkm_fac_n(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pkm.d == 0)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	if (pg.pkm.d == 1)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + ad.x
			+ pg.pkm.mov, (cd.y - pg.pl.pos.y - 1) * SQ_L + pg.pl.mov
			+ 244 + ad.y);
	if (pg.pkm.d == 2)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x, 244
			+ (cd.y - pg.pl.pos.y - 2) * SQ_L + pg.pl.mov + ad.y + pg.pkm.mov);
	if (pg.pkm.d == 3)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 + ad.x
			- pg.pkm.mov, (cd.y - pg.pl.pos.y - 1) * SQ_L + pg.pl.mov
			+ 244 + ad.y);
}

static void	print_mov_pkm_fac_s(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pkm.d == 0)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x, 244
			+ (cd.y - pg.pl.pos.y + 2) * SQ_L - pg.pl.mov + ad.y - pg.pkm.mov);
	if (pg.pkm.d == 1)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + pg.pkm.mov
			+ ad.x, (cd.y - pg.pl.pos.y + 1) * SQ_L - pg.pl.mov + 244 + ad.y);
	if (pg.pkm.d == 2)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	if (pg.pkm.d == 3)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 - pg.pkm.mov
			+ ad.x, (cd.y - pg.pl.pos.y + 1) * SQ_L - pg.pl.mov + 244 + ad.y);
}

static void	print_mov_pkm_fac_e(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pkm.d == 0)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 - pg.pl.mov
			+ ad.x, (cd.y - pg.pl.pos.y + 1) * SQ_L + 244 + ad.y - pg.pkm.mov);
	if (pg.pkm.d == 1)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	if (pg.pkm.d == 2)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 - pg.pl.mov
			+ ad.x, (cd.y - pg.pl.pos.y - 1) * SQ_L + 244 + ad.y + pg.pkm.mov);
	if (pg.pkm.d == 3)
		print_im(pg, im, (cd.x - pg.pl.pos.x + 2) * SQ_L + 500 + ad.x
			- pg.pl.mov - pg.pkm.mov, (cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

static void	print_mov_pkm_fac_w(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pkm.d == 0)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + pg.pl.mov
			+ ad.x, (cd.y - pg.pl.pos.y + 1) * SQ_L + 244 + ad.y - pg.pkm.mov);
	if (pg.pkm.d == 1)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 2) * SQ_L + 500 + ad.x
			+ pg.pl.mov + pg.pkm.mov, (cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	if (pg.pkm.d == 2)
		print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + pg.pl.mov
			+ ad.x, (cd.y - pg.pl.pos.y - 1) * SQ_L + 244 + ad.y + pg.pkm.mov);
	if (pg.pkm.d == 3)
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

void	print_mov_pkm(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pl.d == 0 && pg.pl.mov)
		print_mov_pkm_fac_n(pg, im, cd, ad);
	else if (pg.pl.d == 2 && pg.pl.mov)
		print_mov_pkm_fac_s(pg, im, cd, ad);
	else if (pg.pl.d == 1 && pg.pl.mov)
		print_mov_pkm_fac_e(pg, im, cd, ad);
	else if (pg.pl.d == 3 && pg.pl.mov)
		print_mov_pkm_fac_w(pg, im, cd, ad);
	else
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}
