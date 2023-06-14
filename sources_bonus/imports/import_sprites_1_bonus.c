/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprites_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:37:54 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:00 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	import_player_sprites(t_prog *pg);
void	import_other_char_sprites(t_prog *pg);
void	import_anim_sprites(t_prog *pg);
void	import_map_sprites(t_prog *pg);
void	import_watch_sprites(t_prog *pg);

void	import_fire_starter_sprites(t_prog *pg)
{
	pg->sp.pkm[0][0][0][0] = ft_new_sprite(pg->mlx, "sprites/ouisti_01.xpm");
	pg->sp.pkm[0][0][0][1] = ft_new_sprite(pg->mlx, "sprites/ouisti_11.xpm");
	pg->sp.pkm[0][0][0][2] = ft_new_sprite(pg->mlx, "sprites/ouisti_21.xpm");
	pg->sp.pkm[0][0][0][3] = ft_new_sprite(pg->mlx, "sprites/ouisti_31.xpm");
	pg->sp.pkm[0][0][1][0] = ft_new_sprite(pg->mlx, "sprites/ouisti_02.xpm");
	pg->sp.pkm[0][0][1][1] = ft_new_sprite(pg->mlx, "sprites/ouisti_10.xpm");
	pg->sp.pkm[0][0][1][2] = ft_new_sprite(pg->mlx, "sprites/ouisti_22.xpm");
	pg->sp.pkm[0][0][1][3] = ft_new_sprite(pg->mlx, "sprites/ouisti_30.xpm");
	pg->sp.pkm[0][1][0][0] = ft_new_sprite(pg->mlx, "sprites/chimp_00.xpm");
	pg->sp.pkm[0][1][0][1] = ft_new_sprite(pg->mlx, "sprites/chimp_05.xpm");
	pg->sp.pkm[0][1][0][2] = ft_new_sprite(pg->mlx, "sprites/chimp_04.xpm");
	pg->sp.pkm[0][1][0][3] = ft_new_sprite(pg->mlx, "sprites/chimp_01.xpm");
	pg->sp.pkm[0][1][1][0] = ft_new_sprite(pg->mlx, "sprites/chimp_02.xpm");
	pg->sp.pkm[0][1][1][1] = ft_new_sprite(pg->mlx, "sprites/chimp_07.xpm");
	pg->sp.pkm[0][1][1][2] = ft_new_sprite(pg->mlx, "sprites/chimp_06.xpm");
	pg->sp.pkm[0][1][1][3] = ft_new_sprite(pg->mlx, "sprites/chimp_03.xpm");
	pg->sp.pkm[0][2][0][0] = ft_new_sprite(pg->mlx, "sprites/simia_00.xpm");
	pg->sp.pkm[0][2][0][1] = ft_new_sprite(pg->mlx, "sprites/simia_05.xpm");
	pg->sp.pkm[0][2][0][2] = ft_new_sprite(pg->mlx, "sprites/simia_04.xpm");
	pg->sp.pkm[0][2][0][3] = ft_new_sprite(pg->mlx, "sprites/simia_01.xpm");
	pg->sp.pkm[0][2][1][0] = ft_new_sprite(pg->mlx, "sprites/simia_02.xpm");
	pg->sp.pkm[0][2][1][1] = ft_new_sprite(pg->mlx, "sprites/simia_07.xpm");
	pg->sp.pkm[0][2][1][2] = ft_new_sprite(pg->mlx, "sprites/simia_06.xpm");
	pg->sp.pkm[0][2][1][3] = ft_new_sprite(pg->mlx, "sprites/simia_03.xpm");
}

void	import_water_starter_sprites(t_prog *pg)
{
	pg->sp.pkm[1][0][0][0] = ft_new_sprite(pg->mlx, "sprites/tip_00.xpm");
	pg->sp.pkm[1][0][0][1] = ft_new_sprite(pg->mlx, "sprites/tip_10.xpm");
	pg->sp.pkm[1][0][0][2] = ft_new_sprite(pg->mlx, "sprites/tip_20.xpm");
	pg->sp.pkm[1][0][0][3] = ft_new_sprite(pg->mlx, "sprites/tip_30.xpm");
	pg->sp.pkm[1][0][1][0] = ft_new_sprite(pg->mlx, "sprites/tip_01.xpm");
	pg->sp.pkm[1][0][1][1] = ft_new_sprite(pg->mlx, "sprites/tip_11.xpm");
	pg->sp.pkm[1][0][1][2] = ft_new_sprite(pg->mlx, "sprites/tip_21.xpm");
	pg->sp.pkm[1][0][1][3] = ft_new_sprite(pg->mlx, "sprites/tip_31.xpm");
	pg->sp.pkm[1][1][0][0] = ft_new_sprite(pg->mlx, "sprites/pinpl_00.xpm");
	pg->sp.pkm[1][1][0][1] = ft_new_sprite(pg->mlx, "sprites/pinpl_05.xpm");
	pg->sp.pkm[1][1][0][2] = ft_new_sprite(pg->mlx, "sprites/pinpl_04.xpm");
	pg->sp.pkm[1][1][0][3] = ft_new_sprite(pg->mlx, "sprites/pinpl_01.xpm");
	pg->sp.pkm[1][1][1][0] = ft_new_sprite(pg->mlx, "sprites/pinpl_02.xpm");
	pg->sp.pkm[1][1][1][1] = ft_new_sprite(pg->mlx, "sprites/pinpl_07.xpm");
	pg->sp.pkm[1][1][1][2] = ft_new_sprite(pg->mlx, "sprites/pinpl_06.xpm");
	pg->sp.pkm[1][1][1][3] = ft_new_sprite(pg->mlx, "sprites/pinpl_03.xpm");
	pg->sp.pkm[1][2][0][0] = ft_new_sprite(pg->mlx, "sprites/pingo_00.xpm");
	pg->sp.pkm[1][2][0][1] = ft_new_sprite(pg->mlx, "sprites/pingo_05.xpm");
	pg->sp.pkm[1][2][0][2] = ft_new_sprite(pg->mlx, "sprites/pingo_04.xpm");
	pg->sp.pkm[1][2][0][3] = ft_new_sprite(pg->mlx, "sprites/pingo_01.xpm");
	pg->sp.pkm[1][2][1][0] = ft_new_sprite(pg->mlx, "sprites/pingo_02.xpm");
	pg->sp.pkm[1][2][1][1] = ft_new_sprite(pg->mlx, "sprites/pingo_07.xpm");
	pg->sp.pkm[1][2][1][2] = ft_new_sprite(pg->mlx, "sprites/pingo_06.xpm");
	pg->sp.pkm[1][2][1][3] = ft_new_sprite(pg->mlx, "sprites/pingo_03.xpm");
}

void	import_grass_starter_sprites(t_prog *pg)
{
	pg->sp.pkm[2][0][0][0] = ft_new_sprite(pg->mlx, "sprites/torti_00.xpm");
	pg->sp.pkm[2][0][0][1] = ft_new_sprite(pg->mlx, "sprites/torti_05.xpm");
	pg->sp.pkm[2][0][0][2] = ft_new_sprite(pg->mlx, "sprites/torti_04.xpm");
	pg->sp.pkm[2][0][0][3] = ft_new_sprite(pg->mlx, "sprites/torti_01.xpm");
	pg->sp.pkm[2][0][1][0] = ft_new_sprite(pg->mlx, "sprites/torti_02.xpm");
	pg->sp.pkm[2][0][1][1] = ft_new_sprite(pg->mlx, "sprites/torti_07.xpm");
	pg->sp.pkm[2][0][1][2] = ft_new_sprite(pg->mlx, "sprites/torti_06.xpm");
	pg->sp.pkm[2][0][1][3] = ft_new_sprite(pg->mlx, "sprites/torti_03.xpm");
	pg->sp.pkm[2][1][0][0] = ft_new_sprite(pg->mlx, "sprites/bosk_00.xpm");
	pg->sp.pkm[2][1][0][1] = ft_new_sprite(pg->mlx, "sprites/bosk_05.xpm");
	pg->sp.pkm[2][1][0][2] = ft_new_sprite(pg->mlx, "sprites/bosk_04.xpm");
	pg->sp.pkm[2][1][0][3] = ft_new_sprite(pg->mlx, "sprites/bosk_01.xpm");
	pg->sp.pkm[2][1][1][0] = ft_new_sprite(pg->mlx, "sprites/bosk_02.xpm");
	pg->sp.pkm[2][1][1][1] = ft_new_sprite(pg->mlx, "sprites/bosk_07.xpm");
	pg->sp.pkm[2][1][1][2] = ft_new_sprite(pg->mlx, "sprites/bosk_06.xpm");
	pg->sp.pkm[2][1][1][3] = ft_new_sprite(pg->mlx, "sprites/bosk_03.xpm");
	pg->sp.pkm[2][2][0][0] = ft_new_sprite(pg->mlx, "sprites/torte_00.xpm");
	pg->sp.pkm[2][2][0][1] = ft_new_sprite(pg->mlx, "sprites/torte_05.xpm");
	pg->sp.pkm[2][2][0][2] = ft_new_sprite(pg->mlx, "sprites/torte_04.xpm");
	pg->sp.pkm[2][2][0][3] = ft_new_sprite(pg->mlx, "sprites/torte_01.xpm");
	pg->sp.pkm[2][2][1][0] = ft_new_sprite(pg->mlx, "sprites/torte_02.xpm");
	pg->sp.pkm[2][2][1][1] = ft_new_sprite(pg->mlx, "sprites/torte_07.xpm");
	pg->sp.pkm[2][2][1][2] = ft_new_sprite(pg->mlx, "sprites/torte_06.xpm");
	pg->sp.pkm[2][2][1][3] = ft_new_sprite(pg->mlx, "sprites/torte_03.xpm");
}

void	import_case_anim_sprites(t_prog *pg)
{
	pg->sp.pkm_anim[0] = ft_new_sprite(pg->mlx, "sprites/pk_anim_00.xpm");
	pg->sp.pkm_anim[1] = ft_new_sprite(pg->mlx, "sprites/pk_anim_01.xpm");
	pg->sp.pkm_anim[2] = ft_new_sprite(pg->mlx, "sprites/pk_anim_02.xpm");
	pg->sp.pkm_anim[3] = ft_new_sprite(pg->mlx, "sprites/pk_anim_03.xpm");
	pg->sp.pkm_anim[4] = ft_new_sprite(pg->mlx, "sprites/pk_anim_04.xpm");
	pg->sp.pkm_anim[5] = ft_new_sprite(pg->mlx, "sprites/pk_anim_05.xpm");
	pg->sp.pkm_anim[6] = ft_new_sprite(pg->mlx, "sprites/pk_anim_06.xpm");
	pg->sp.pkm_anim[7] = ft_new_sprite(pg->mlx, "sprites/pk_anim_07.xpm");
	pg->sp.pkm_anim[8] = ft_new_sprite(pg->mlx, "sprites/pk_anim_08.xpm");
	pg->sp.pkm_anim[9] = ft_new_sprite(pg->mlx, "sprites/pk_anim_09.xpm");
	pg->sp.pkm_anim[10] = ft_new_sprite(pg->mlx, "sprites/pk_anim_10.xpm");
	pg->sp.pkm_anim[11] = ft_new_sprite(pg->mlx, "sprites/pk_anim_11.xpm");
	pg->sp.pkm_anim[12] = ft_new_sprite(pg->mlx, "sprites/pk_anim_12.xpm");
	pg->sp.pkm_anim[13] = ft_new_sprite(pg->mlx, "sprites/pk_anim_13.xpm");
	pg->sp.pkm_anim[14] = ft_new_sprite(pg->mlx, "sprites/pk_anim_14.xpm");
	pg->sp.pkm_anim[15] = ft_new_sprite(pg->mlx, "sprites/pk_anim_15.xpm");
	pg->sp.pkm_anim[16] = ft_new_sprite(pg->mlx, "sprites/pk_anim_16.xpm");
	pg->sp.pkm_anim[17] = ft_new_sprite(pg->mlx, "sprites/pk_anim_17.xpm");
	pg->sp.pkm_anim[18] = ft_new_sprite(pg->mlx, "sprites/pk_anim_18.xpm");
	pg->sp.pkm_anim[19] = ft_new_sprite(pg->mlx, "sprites/pk_anim_19.xpm");
	pg->sp.pkm_anim[20] = ft_new_sprite(pg->mlx, "sprites/pk_anim_20.xpm");
	pg->sp.pkm_anim[21] = ft_new_sprite(pg->mlx, "sprites/pk_anim_21.xpm");
	pg->sp.pkm_anim[22] = ft_new_sprite(pg->mlx, "sprites/pk_anim_22.xpm");
	pg->sp.pkm_anim[23] = ft_new_sprite(pg->mlx, "sprites/pk_anim_23.xpm");
}

void	import_all_sprites(t_prog *pg)
{
	pg->sp.excl = ft_new_sprite(pg->mlx, "sprites/excl.xpm");
	pg->sp.dk[0] = ft_new_sprite(pg->mlx, "sprites/darkness_n.xpm");
	pg->sp.dk[1] = ft_new_sprite(pg->mlx, "sprites/darkness_e.xpm");
	pg->sp.dk[2] = ft_new_sprite(pg->mlx, "sprites/darkness_s.xpm");
	pg->sp.dk[3] = ft_new_sprite(pg->mlx, "sprites/darkness_w.xpm");
	pg->sp.arw = ft_new_sprite(pg->mlx, "sprites/arrow.xpm");
	pg->sp.crs[0] = ft_new_sprite(pg->mlx, "sprites/cursor_l.xpm");
	pg->sp.crs[1] = ft_new_sprite(pg->mlx, "sprites/cursor_c.xpm");
	pg->sp.crs[2] = ft_new_sprite(pg->mlx, "sprites/cursor_r.xpm");
	pg->sp.bol_crs = ft_new_sprite(pg->mlx, "sprites/cursor2.xpm");
	pg->sp.pkm_sel[0] = ft_new_sprite(pg->mlx, "sprites/ouisti sel fin.xpm");
	pg->sp.pkm_sel[1] = ft_new_sprite(pg->mlx, "sprites/tip sel fin.xpm");
	pg->sp.pkm_sel[2] = ft_new_sprite(pg->mlx, "sprites/torti sel fin.xpm");
	pg->sp.dia_box[0] = ft_new_sprite(pg->mlx, "sprites/dialogue_box_en.xpm");
	pg->sp.dia_box[1] = ft_new_sprite(pg->mlx, "sprites/dialogue_box_ex.xpm");
	import_player_sprites(pg);
	import_other_char_sprites(pg);
	import_anim_sprites(pg);
	import_map_sprites(pg);
	import_watch_sprites(pg);
	import_fire_starter_sprites(pg);
	import_water_starter_sprites(pg);
	import_grass_starter_sprites(pg);
	import_case_anim_sprites(pg);
}
