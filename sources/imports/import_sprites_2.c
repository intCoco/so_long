/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprites_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:37:54 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/12 17:54:26 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	import_player_sprites(t_prog *pg)
{
	pg->sp.pl[0][0][0] = ft_new_sprite(pg->mlx, "sprites/tile012.xpm");
	pg->sp.pl[0][0][1] = ft_new_sprite(pg->mlx, "sprites/tile008.xpm");
	pg->sp.pl[0][0][2] = ft_new_sprite(pg->mlx, "sprites/tile000.xpm");
	pg->sp.pl[0][0][3] = ft_new_sprite(pg->mlx, "sprites/tile004.xpm");
	pg->sp.pl[0][1][0] = ft_new_sprite(pg->mlx, "sprites/tile013.xpm");
	pg->sp.pl[0][1][1] = ft_new_sprite(pg->mlx, "sprites/tile009.xpm");
	pg->sp.pl[0][1][2] = ft_new_sprite(pg->mlx, "sprites/tile001.xpm");
	pg->sp.pl[0][1][3] = ft_new_sprite(pg->mlx, "sprites/tile005.xpm");
	pg->sp.pl[0][2][0] = ft_new_sprite(pg->mlx, "sprites/tile015.xpm");
	pg->sp.pl[0][2][1] = ft_new_sprite(pg->mlx, "sprites/tile011.xpm");
	pg->sp.pl[0][2][2] = ft_new_sprite(pg->mlx, "sprites/tile003.xpm");
	pg->sp.pl[0][2][3] = ft_new_sprite(pg->mlx, "sprites/tile007.xpm");
	pg->sp.pl[1][0][0] = ft_new_sprite(pg->mlx, "sprites/pl_run_12.xpm");
	pg->sp.pl[1][0][1] = ft_new_sprite(pg->mlx, "sprites/pl_run_08.xpm");
	pg->sp.pl[1][0][2] = ft_new_sprite(pg->mlx, "sprites/pl_run_00.xpm");
	pg->sp.pl[1][0][3] = ft_new_sprite(pg->mlx, "sprites/pl_run_04.xpm");
	pg->sp.pl[1][1][0] = ft_new_sprite(pg->mlx, "sprites/pl_run_13.xpm");
	pg->sp.pl[1][1][1] = ft_new_sprite(pg->mlx, "sprites/pl_run_09.xpm");
	pg->sp.pl[1][1][2] = ft_new_sprite(pg->mlx, "sprites/pl_run_01.xpm");
	pg->sp.pl[1][1][3] = ft_new_sprite(pg->mlx, "sprites/pl_run_05.xpm");
	pg->sp.pl[1][2][0] = ft_new_sprite(pg->mlx, "sprites/pl_run_15.xpm");
	pg->sp.pl[1][2][1] = ft_new_sprite(pg->mlx, "sprites/pl_run_11.xpm");
	pg->sp.pl[1][2][2] = ft_new_sprite(pg->mlx, "sprites/pl_run_03.xpm");
	pg->sp.pl[1][2][3] = ft_new_sprite(pg->mlx, "sprites/pl_run_07.xpm");
}

void	import_other_char_sprites(t_prog *pg)
{
	pg->sp.en[0][0] = ft_new_sprite(pg->mlx, "sprites/mont012.xpm");
	pg->sp.en[0][1] = ft_new_sprite(pg->mlx, "sprites/mont008.xpm");
	pg->sp.en[0][2] = ft_new_sprite(pg->mlx, "sprites/mont000.xpm");
	pg->sp.en[0][3] = ft_new_sprite(pg->mlx, "sprites/mont004.xpm");
	pg->sp.en[1][0] = ft_new_sprite(pg->mlx, "sprites/mont013.xpm");
	pg->sp.en[1][1] = ft_new_sprite(pg->mlx, "sprites/mont009.xpm");
	pg->sp.en[1][2] = ft_new_sprite(pg->mlx, "sprites/mont001.xpm");
	pg->sp.en[1][3] = ft_new_sprite(pg->mlx, "sprites/mont005.xpm");
	pg->sp.en[2][0] = ft_new_sprite(pg->mlx, "sprites/mont015.xpm");
	pg->sp.en[2][1] = ft_new_sprite(pg->mlx, "sprites/mont011.xpm");
	pg->sp.en[2][2] = ft_new_sprite(pg->mlx, "sprites/mont003.xpm");
	pg->sp.en[2][3] = ft_new_sprite(pg->mlx, "sprites/mont007.xpm");
	pg->sp.pc[0] = ft_new_sprite(pg->mlx, "sprites/pick_tile003.xpm");
	pg->sp.pc[1] = ft_new_sprite(pg->mlx, "sprites/pick_tile002.xpm");
	pg->sp.pc[2] = ft_new_sprite(pg->mlx, "sprites/pick_tile000.xpm");
	pg->sp.pc[3] = ft_new_sprite(pg->mlx, "sprites/pick_tile001.xpm");
	pg->sp.fpl[0] = ft_new_sprite(pg->mlx, "sprites/fpl_tile012.xpm");
	pg->sp.fpl[1] = ft_new_sprite(pg->mlx, "sprites/fpl_tile008.xpm");
	pg->sp.fpl[2] = ft_new_sprite(pg->mlx, "sprites/fpl_tile000.xpm");
	pg->sp.fpl[3] = ft_new_sprite(pg->mlx, "sprites/fpl_tile004.xpm");
	pg->sp.fpl_sav = ft_new_sprite(pg->mlx, "sprites/fpl_sav.xpm");
	pg->sp.fpl_dia = ft_new_sprite(pg->mlx, "sprites/fpl_intro.xpm");
}

void	import_anim_sprites(t_prog *pg)
{
	pg->sp.anim[0] = ft_new_sprite(pg->mlx, "sprites/anim_09.xpm");
	pg->sp.anim[1] = ft_new_sprite(pg->mlx, "sprites/anim_08.xpm");
	pg->sp.anim[2] = ft_new_sprite(pg->mlx, "sprites/anim_07.xpm");
	pg->sp.anim[3] = ft_new_sprite(pg->mlx, "sprites/anim_06.xpm");
	pg->sp.anim[4] = ft_new_sprite(pg->mlx, "sprites/anim_05.xpm");
	pg->sp.anim[5] = ft_new_sprite(pg->mlx, "sprites/anim_04.xpm");
	pg->sp.anim[6] = ft_new_sprite(pg->mlx, "sprites/anim_03.xpm");
	pg->sp.anim[7] = ft_new_sprite(pg->mlx, "sprites/anim_02.xpm");
	pg->sp.anim[8] = ft_new_sprite(pg->mlx, "sprites/anim_01.xpm");
	pg->sp.anim[9] = ft_new_sprite(pg->mlx, "sprites/anim_00.xpm");
	pg->sp.anim2[0] = ft_new_sprite(pg->mlx, "sprites/anim_001.xpm");
	pg->sp.anim2[1] = ft_new_sprite(pg->mlx, "sprites/anim_002.xpm");
	pg->sp.intro[0] = ft_new_sprite(pg->mlx, "sprites/introds00.xpm");
	pg->sp.intro[1] = ft_new_sprite(pg->mlx, "sprites/introds01.xpm");
	pg->sp.intro[2] = ft_new_sprite(pg->mlx, "sprites/introds02.xpm");
	pg->sp.intro[3] = ft_new_sprite(pg->mlx, "sprites/introds03.xpm");
	pg->sp.intro[4] = ft_new_sprite(pg->mlx, "sprites/introds04.xpm");
	pg->sp.intro[5] = ft_new_sprite(pg->mlx, "sprites/introds05.xpm");
	pg->sp.intro[6] = ft_new_sprite(pg->mlx, "sprites/introds06.xpm");
}

void	import_map_sprites(t_prog *pg)
{
	pg->sp.flower[1] = ft_new_sprite(pg->mlx, "sprites/weed.xpm");
	pg->sp.flower[0] = ft_new_sprite(pg->mlx, "sprites/flower.xpm");
	pg->sp.flower[2] = ft_new_sprite(pg->mlx, "sprites/flower3.xpm");
	pg->sp.flower[3] = ft_new_sprite(pg->mlx, "sprites/flower4.xpm");
	pg->sp.flower[4] = ft_new_sprite(pg->mlx, "sprites/flower5.xpm");
	pg->sp.flower[5] = ft_new_sprite(pg->mlx, "sprites/flower6.xpm");
	pg->sp.block[0] = ft_new_sprite(pg->mlx, "sprites/block1.xpm");
	pg->sp.block[1] = ft_new_sprite(pg->mlx, "sprites/block2.xpm");
	pg->sp.block[2] = ft_new_sprite(pg->mlx, "sprites/block3.xpm");
	pg->sp.block[3] = ft_new_sprite(pg->mlx, "sprites/block4.xpm");
	pg->sp.block[4] = ft_new_sprite(pg->mlx, "sprites/rock.xpm");
	pg->sp.block[5] = ft_new_sprite(pg->mlx, "sprites/fence.xpm");
	pg->sp.block[6] = ft_new_sprite(pg->mlx, "sprites/interfence.xpm");
	pg->sp.pkb = ft_new_sprite(pg->mlx, "sprites/pokeball.xpm");
	pg->sp.wall = ft_new_sprite(pg->mlx, "sprites/bigtree.xpm");
	pg->sp.ground = ft_new_sprite(pg->mlx, "sprites/ground.xpm");
}

void	import_watch_sprites(t_prog *pg)
{
	pg->sp.bg = ft_new_sprite(pg->mlx, "sprites/watch.xpm");
	pg->sp.nb[0] = ft_new_sprite(pg->mlx, "sprites/nb0.xpm");
	pg->sp.nb[1] = ft_new_sprite(pg->mlx, "sprites/nb1.xpm");
	pg->sp.nb[2] = ft_new_sprite(pg->mlx, "sprites/nb2.xpm");
	pg->sp.nb[3] = ft_new_sprite(pg->mlx, "sprites/nb3.xpm");
	pg->sp.nb[4] = ft_new_sprite(pg->mlx, "sprites/nb4.xpm");
	pg->sp.nb[5] = ft_new_sprite(pg->mlx, "sprites/nb5.xpm");
	pg->sp.nb[6] = ft_new_sprite(pg->mlx, "sprites/nb6.xpm");
	pg->sp.nb[7] = ft_new_sprite(pg->mlx, "sprites/nb7.xpm");
	pg->sp.nb[8] = ft_new_sprite(pg->mlx, "sprites/nb8.xpm");
	pg->sp.nb[9] = ft_new_sprite(pg->mlx, "sprites/nb9.xpm");
}
