/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:19:14 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/06 21:12:46 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <math.h>


void	print_im(t_prog pg, t_image im, int x, int y)
{
	mlx_put_image_to_window(pg.mlx, pg.wdw.ref, im.ref,
		x - (im.size.x / 2), y - im.size.y);
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
			+ 500 , (cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	else
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

void	print_mov_pkm(t_prog pg, t_image im, t_vector cd, t_vector ad)
{
	if (pg.pl.d == 0 && pg.pl.mov)
	{
		if (pg.pkm.d == 0)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
		if (pg.pkm.d == 1)
			print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + ad.x + pg.pkm.mov,
				(cd.y - pg.pl.pos.y - 1) * SQ_L + pg.pl.mov + 244 + ad.y);
		if (pg.pkm.d == 2)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y - 2) * SQ_L + pg.pl.mov + 244 + ad.y + pg.pkm.mov);
		if (pg.pkm.d == 3)
			print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 + ad.x - pg.pkm.mov,
				(cd.y - pg.pl.pos.y - 1) * SQ_L + pg.pl.mov + 244 + ad.y);
	}
	else if (pg.pl.d == 2 && pg.pl.mov)
	{
		if (pg.pkm.d == 0)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y + 2) * SQ_L - pg.pl.mov + 244 + ad.y - pg.pkm.mov);
		if (pg.pkm.d == 1)
			print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + ad.x + pg.pkm.mov,
				(cd.y - pg.pl.pos.y + 1) * SQ_L - pg.pl.mov + 244 + ad.y);
		if (pg.pkm.d == 2)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
		if (pg.pkm.d == 3)
			print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 + ad.x - pg.pkm.mov,
				(cd.y - pg.pl.pos.y + 1) * SQ_L - pg.pl.mov + 244 + ad.y);
	}
	else if (pg.pl.d == 1 && pg.pl.mov)
	{
		if (pg.pkm.d == 0)
			print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 + ad.x - pg.pl.mov,
				(cd.y - pg.pl.pos.y + 1) * SQ_L + 244 + ad.y - pg.pkm.mov);
		if (pg.pkm.d == 1)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
		if (pg.pkm.d == 2)
			print_im(pg, im, (cd.x - pg.pl.pos.x + 1) * SQ_L + 500 + ad.x - pg.pl.mov,
				(cd.y - pg.pl.pos.y - 1) * SQ_L + 244 + ad.y + pg.pkm.mov);
		if (pg.pkm.d == 3)
			print_im(pg, im, (cd.x - pg.pl.pos.x + 2) * SQ_L + 500 + ad.x - pg.pl.mov - pg.pkm.mov,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	}
	else if (pg.pl.d == 3 && pg.pl.mov)
	{
		if (pg.pkm.d == 0)
			print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + ad.x + pg.pl.mov,
				(cd.y - pg.pl.pos.y + 1) * SQ_L + 244 + ad.y - pg.pkm.mov);
		if (pg.pkm.d == 1)
			print_im(pg, im, (cd.x - pg.pl.pos.x - 2) * SQ_L + 500 + ad.x + pg.pl.mov + pg.pkm.mov,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
		if (pg.pkm.d == 2)
			print_im(pg, im, (cd.x - pg.pl.pos.x - 1) * SQ_L + 500 + ad.x + pg.pl.mov,
				(cd.y - pg.pl.pos.y - 1) * SQ_L + 244 + ad.y + pg.pkm.mov);
		if (pg.pkm.d == 3)
			print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
				(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
	}
	else
		print_im(pg, im, (cd.x - pg.pl.pos.x) * SQ_L + 500 + ad.x,
			(cd.y - pg.pl.pos.y) * SQ_L + 244 + ad.y);
}

t_vector	ad(int x, int y)
{
	t_vector	ad;

	ad.x = x;
	ad.y = y;
	
	return (ad);
}

void	print_ground(t_prog pg)
{
	t_vector cd;

	cd.y = pg.pl.pos.y - 7;
	while (cd.y < pg.pl.pos.y + 8)
	{
		cd.x = pg.pl.pos.x - 7;
		while (cd.x < pg.pl.pos.x + 8)
		{
			if (cd.y >= -1 && cd.x >= -1 && cd.y <= pg.map.size.y + 1 && cd.x
				<= pg.map.size.x + 1)
				print_mov(pg, pg.sp.ground, cd, ad(0, 11));
			if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg.map.size.y && cd.x <=
				pg.map.size.x)
				if (pg.map.tab2[cd.y][cd.x] >= '2' && pg.map.tab2[cd.y][cd.x]
					<= '7')
					print_mov(pg, pg.sp.flower[pg.map.tab2[cd.y][cd.x] - 50],
						cd, ad(0, 5));
			cd.x++;
		}
		cd.y++;
	}
}

void	print_nb(t_prog pg)
{
	char	*str;
	int		i;

	i = 4;
	print_im(pg, pg.sp.bg, 500, 918);
	str = malloc(5);
	while (i >= 0)
	{
		str[i--] = (pg.pl.count % 10) + '0';
		pg.pl.count /= 10;
	}
	i = 0;
	while (i < 5)
	{
		print_im(pg, pg.sp.nb[str[i] - 48], (i - 3) * 29 + 500, 712); 
		i++;
	}
	free(str);
}

t_prog	ft_find_en(t_prog pg)
{
	pg.en.pos.y = 0;
	while (pg.map.tab[pg.en.pos.y])
	{
		pg.en.pos.x = 0;
		while (pg.map.tab[pg.en.pos.y][pg.en.pos.x] != 'm'
			&& pg.map.tab[pg.en.pos.y][pg.en.pos.x])
			pg.en.pos.x++;
		if (pg.map.tab[pg.en.pos.y][pg.en.pos.x] == 'm')
			return (pg);
		pg.en.pos.y++;
	}
	return (pg);
}

void	en_mov(t_prog *pg, int x, int y)
{
	pg->en.pos.x += x;
	pg->en.pos.y += y;
	pg->en.mov = 1;
	pg->en.count += 1;
}

t_prog	ft_interac_en(t_prog pg, t_vector *cd)
{
	if (pg.excl_b == 1)
	{
		pg.pl.d = pg.en.d + 2;
		if (pg.en.d >= 2)
			pg.pl.d -= 4;
		pg.excl_b = 2;
	}
	if (pg.excl_b == 2 && pg.en.mov == 0)
	{
		pg.map.tab[pg.en.pos.y][pg.en.pos.x] = 'x';
		if (pg.en.d == 0 && pg.map.tab[cd->y - 1][cd->x] != 'p')
			en_mov(&pg, 0, -1);
		else if (pg.en.d == 1 && pg.map.tab[cd->y][cd->x + 1] != 'p')
			en_mov(&pg, 1, 0);
		else if (pg.en.d == 2 && pg.map.tab[cd->y + 1][cd->x] != 'p')
			en_mov(&pg, 0, 1);
		else if (pg.en.d == 3 && pg.map.tab[cd->y][cd->x - 1] != 'p')
			en_mov(&pg, -1, 0);
		else
			pg.excl_b = 3;
		pg.map.tab[pg.en.pos.y][pg.en.pos.x] = 'm';
	}
	return (pg);
}

t_prog	ft_encheck(t_prog pg)
{
	int x;
	int y;

	pg = ft_find_en(pg);
	x = pg.en.pos.x;
	y = pg.en.pos.y;
	if (pg.en.d == 0)
		while ((pg.map.tab[y][x] == 'm' || pg.map.tab[y][x] == 'x') && y > pg.en.pos.y - 3)
			y--;
	else if (pg.en.d == 2)
		while ((pg.map.tab[y][x] == 'm' || pg.map.tab[y][x] == 'x') && y < pg.en.pos.y + 3)
			y++;
	else if (pg.en.d == 1)
		while ((pg.map.tab[y][x] == 'm' || pg.map.tab[y][x] == 'x') && x < pg.en.pos.x + 3)
			x++;
	else if (pg.en.d == 3)
		while ((pg.map.tab[y][x] == 'm' || pg.map.tab[y][x] == 'x') && x > pg.en.pos.x - 3)
			x--;
	if (pg.map.tab[y][x] == 'p' && pg.excl_b == 0 && pg.pl.mov == 0)
	{
		pg.excl_b = 1;
		pg.timer = 1;
		pg.run = 0;
	}
	if (pg.en.mov == 0 && pg.timer == 0)
		pg = ft_interac_en(pg, &pg.en.pos);
	return (pg);
}

void	ft_find_ex(t_prog *pg)
{
	pg->ex.pos.y = 0;
	while (pg->map.tab[pg->ex.pos.y])
	{
		pg->ex.pos.x = 0;
		while (pg->map.tab[pg->ex.pos.y][pg->ex.pos.x] != 'e'
			&& pg->map.tab[pg->ex.pos.y][pg->ex.pos.x])
			pg->ex.pos.x++;
		if (pg->map.tab[pg->ex.pos.y][pg->ex.pos.x] == 'e')
			break;
		pg->ex.pos.y++;
	}
}

void	rot_exit(t_prog *pg)
{
	t_vector	cd_r;

	ft_find_ex(pg);
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

void	print_chars(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == 'e')
	{
		rot_exit(&pg);
		if (pg.map.obj.c_nb != 0)
			print_mov(pg, pg.sp.fpl_sav, cd, ad(0, 0));
		if (pg.map.obj.c_nb == 0)
			print_mov(pg, pg.sp.fpl[pg.ex.d], cd, ad(0, 0));
	}
	else if (pg.map.tab[cd.y][cd.x] == 'm')
	{
		if (pg.en.mov == 0)
			print_mov(pg, pg.sp.en[0][pg.en.d], cd, ad(0, 0));
		else if (pg.en.mov != 0)
			print_mov(pg, pg.sp.en[pg.en.count % 2 + 1][pg.en.d], cd, ad(0, 0));
	}
	else if (pg.map.tab[cd.y][cd.x] == 'p')
	{
		if (pg.pick >= 1)
			print_im(pg, pg.sp.pc[pg.pl.d], 500, 244);
		if (pg.pl.mov == 0 && pg.pick == 0)
			print_im(pg, pg.sp.pl[pg.run % 2][0][pg.pl.d], 500, 244);
		if (pg.pl.mov != 0)
			print_im(pg, pg.sp.pl[pg.run % 2][pg.pl.count % 2 + 1][pg.pl.d],
				500, 244);
	}
	else if (pg.map.tab[cd.y][cd.x] == '.')
		print_mov_pkm(pg, pg.sp.pkm[pg.pkm_nb][pg.pkm_ev][pg.pkm.count % 2][pg.pkm.d], cd, ad(0, 0));
}

void	print_darkness(t_prog pg)
{
	t_vector	cd;

	cd.x = -4;
	cd.y = 0;
	while (++cd.x <= pg.map.size.x + 2 && ++cd.x > -10)
		print_mov(pg, pg.sp.dk[0], cd, ad(-SQ_L / 2, 0));
	cd.x = pg.map.size.x + 1;
	cd.y = -4;
	while (++cd.y <= pg.map.size.y + 2 && ++cd.y > -10)
		print_mov(pg, pg.sp.dk[1], cd, ad(SQ_L / 2 + 10, -32));
	cd.x = -2;
	cd.y = -2;
	while (++cd.y <= pg.map.size.y + 2 && ++cd.y > -10)
		print_mov(pg, pg.sp.dk[3], cd, ad(10, -32));
	cd.x = -4;
	cd.y = pg.map.size.y + 1;
	while (++cd.x <= pg.map.size.x + 2 && ++cd.x > -10)
		print_mov(pg, pg.sp.dk[2], cd, ad(-SQ_L / 2, 70));
}

void	print_up_walls(t_prog pg)
{
	t_vector	cd;

	cd.x = -2;
	cd.y = 0;
	while (++cd.x <= pg.map.size.x + 1 && ++cd.x > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(SQ_L / 2, -48));
			if (cd.x >= 0)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
	cd.x = 0;
	cd.y = 0;
	while (++cd.y <= pg.map.size.y + 1 && ++cd.y > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L * 2, -15));
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
	cd.x = pg.map.size.x + 1;
	cd.y = 0;
	while (++cd.y < pg.map.size.y + 1 && ++cd.y > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			print_mov(pg, pg.sp.wall, cd, ad(SQ_L, -15));
			if (cd.y < pg.map.size.y + 1)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
		}
	}
}

void	ft_print_down_walls(t_prog pg)
{
	t_vector	cd;

	cd.x = 0;
	cd.y = pg.map.size.y + 1;
	while (++cd.x <= pg.map.size.x + 1 && ++cd.x > -10)
	{
		if (cd.x >= pg.pl.pos.x - 6 && cd.x <= pg.pl.pos.x + 7
			&& cd.y >= pg.pl.pos.y - 6 && cd.y <= pg.pl.pos.y + 7)
		{
			if (cd.x >= 0)
				print_mov(pg, pg.sp.wall, cd, ad(-SQ_L / 2, 15));
			print_mov(pg, pg.sp.wall, cd, ad(-SQ_L - SQ_L / 2, 78));
		}
	}
}

void	print_collec(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == 'c')
		print_mov(pg, pg.sp.pkb, cd, ad(0, 0));
	else if (pg.map.tab[cd.y][cd.x] == 'p' && pg.pick >= 1 && pg.pick <= 30)
		print_mov(pg, pg.sp.pkb, cd, ad(0, -sqrt(pg.pick * 2)));
}

void	print_blocks(t_prog pg, t_vector cd)
{
	if (pg.map.tab[cd.y][cd.x] == '2')
		print_mov(pg, pg.sp.wall, cd, ad(SQ_L / 2, 15));
	if (pg.map.tab2[cd.y][cd.x] >= 'a' && pg.map.tab2[cd.y][cd.x] <= 'a' + 5)
		print_mov(pg, pg.sp.block[pg.map.tab2[cd.y][cd.x] - 97], cd, ad(0, 0));
}

void	print_fences(t_prog pg, t_vector cd)
{
	if (pg.map.tab2[cd.y][cd.x] == 'h' || pg.map.tab2[cd.y][cd.x] == 'v' || pg.map.tab2[cd.y][cd.x] == 'z')
	{
		print_mov(pg, pg.sp.block[5], cd, ad(0, 0));
		if (pg.map.tab2[cd.y][cd.x + 1] == 'h' || pg.map.tab2[cd.y][cd.x + 1] == 'z')
			print_mov(pg, pg.sp.block[6], cd, ad(SQ_L / 2, 0));
		if (pg.map.tab2[cd.y + 1][cd.x] == 'v' || pg.map.tab2[cd.y + 1][cd.x] == 'z')
			print_mov(pg, pg.sp.block[5], cd, ad(0, SQ_L / 2));
	}
}

void	print_fight_anim(t_prog pg)
{
	double j;

	j = pg.i;
	if (pg.i <= 9)
		print_im(pg, pg.sp.anim[pg.i], 500, 240 + pg.sp.anim[pg.i].size.y / 2);
	else if (pg.i == 10)
	{
		print_im(pg, pg.sp.anim2[0], 500 - pg.split, 240 + pg.sp.anim2[0].size.y / 2);
		print_im(pg, pg.sp.anim2[1], 500 + pg.split, 240 + pg.sp.anim2[1].size.y / 2);
	}
}

void	print_excl(t_prog pg)
{
	if (pg.timer != 0 && pg.timer < 15)
		print_im(pg, pg.sp.excl, (pg.en.pos.x - pg.pl.pos.x) * SQ_L + 500, (pg.en.pos.y - pg.pl.pos.y - 1) * SQ_L + 270 - pg.timer);
	if (pg.timer != 0 && pg.timer >= 15)
		print_im(pg, pg.sp.excl, (pg.en.pos.x - pg.pl.pos.x) * SQ_L + 500, (pg.en.pos.y - pg.pl.pos.y - 1) * SQ_L + 270);
}

void	print_game(t_prog pg)
{
	t_vector	cd;
	int i;
	int j;

	i = 500;
	j = 500;

	mlx_clear_window(pg.mlx, pg.wdw.ref);
	if (pg.begin != 0 && pg.end == 0)
	{
		if (pg.i < 10 && !((pg.tanim > 25 && pg.tanim < 50) || (pg.tanim > 75 && pg.tanim < 100)) && pg.begin > 1)
		{
			print_ground(pg);
			print_up_walls(pg);
			cd.y = pg.pl.pos.y - 7;
			while (cd.y < pg.pl.pos.y + 8)
			{
				cd.x = pg.pl.pos.x - 7;
				while (cd.x < pg.pl.pos.x + 8)
				{
					if (cd.y >= 0 && cd.x >= 0 && cd.y <= pg.map.size.y && cd.x <= pg.map.size.x)
					{
						print_collec(pg, cd);
						print_chars(pg, cd);
						print_fences(pg, cd);
						print_blocks(pg, cd);
						print_excl(pg);
					}
					cd.x++;
				}
				cd.y++;
			}
			ft_print_down_walls(pg);
			print_darkness(pg);
		}
		else if (pg.begin == 1)
		{
			print_im(pg, pg.sp.pkm_anim[pg.i], 500, 410);
			if (pg.i == 23 && pg.select == 0)
			{
				print_im(pg, pg.sp.crs[pg.cur_sel], 500, 400 + pg.timer2 / 3);
				print_im(pg, pg.sp.arw, 681, 406 + pg.timer2 / 10);
			}
			if (pg.i == 23 && pg.select == 1)
			{
				print_im(pg, pg.sp.pkm_sel[pg.pkm_nb], 500, 408);
				print_im(pg, pg.sp.bol_crs, 607, 286 - pg.bol * 28);
			}
		}
		if (pg.excl_b == 3 && pg.tanim >= 100)
			print_fight_anim(pg);
		if (pg.begin == 2)
		{
			print_im(pg, pg.sp.fpl_dia, 360, 340);
			print_im(pg, pg.sp.dia_box[1], 500, 410);
			print_im(pg, pg.sp.arw, 710, 405 + pg.timer2 / 10);
		}
		if (pg.excl_b == 3 && pg.tanim == 0)
		{
			print_im(pg, pg.sp.dia_box[0], 500, 410);
			print_im(pg, pg.sp.arw, 710, 405 + pg.timer2 / 10);
		}
		print_im(pg, pg.sp.intro[0], 500, 1000);
		if (pg.begin > 1)
			print_nb(pg);
	}
	else if (pg.end == 0)
		print_im(pg, pg.sp.intro[6 - pg.i], 500, 1000);
	else
		print_im(pg, pg.sp.intro[pg.i], 500, 1000);
	//ft_print_pathfinding(pg.map);
}

int	ft_close(t_map *map, char *err_txt)
{
	int	i;

	i = -1;
	while (++i < map->size.y + 1)
	{
		if (map->tab[i])
			free(map->tab[i]);
		if (map->tab2[i])
			free(map->tab2[i]);
	}
	if (map->tab)
		free(map->tab);
	if (map->tab2)
		free(map->tab2);
	if (err_txt != NULL)
		exit(ft_printf("%s\n", err_txt));
	exit(0);
}

int	main_args_parsing(int ac, char **av);

int	main(int ac, char **av)
{
	int		fd;
	t_prog	pg;

	if (main_args_parsing(ac, av) != 0)
		return (1);
	ft_bzero(&pg, sizeof(t_prog));
	import_all_sprites(&pg);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFailed to open the map\n\n"));
	pg.map.tab = ft_readmap(fd);
	close(fd);
	if (!pg.map.tab)
		ft_close(&pg.map, "Malloc error\n");
	pg = ft_mapinit(pg);
	pg.mlx = mlx_init();
	pg.wdw = ft_new_window(pg.mlx, 1000, 1000, "Pokemon : Gotta catch em all");
	mlx_hook(pg.wdw.ref, 2, 0, ft_input, &pg);
	mlx_hook(pg.wdw.ref, 17, 0, ft_close, &pg);
	mlx_loop_hook(pg.mlx, *ft_update, &pg);
	mlx_loop(pg.mlx);
}
