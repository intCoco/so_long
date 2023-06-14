/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:37:54 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:30 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong.h"

void	import_all_sprites(t_prog *pg)
{
	pg->sp.wall = ft_new_sprite(pg->mlx, "sprites/block1.xpm");
	pg->sp.pkb = ft_new_sprite(pg->mlx, "sprites/pokeball.xpm");
	pg->sp.ground = ft_new_sprite(pg->mlx, "sprites/ground.xpm");
	pg->sp.intro = ft_new_sprite(pg->mlx, "sprites/introds00.xpm");
	pg->sp.fpl = ft_new_sprite(pg->mlx, "sprites/fpl_tile000.xpm");
	pg->sp.pl[0] = ft_new_sprite(pg->mlx, "sprites/tile012.xpm");
	pg->sp.pl[1] = ft_new_sprite(pg->mlx, "sprites/tile008.xpm");
	pg->sp.pl[2] = ft_new_sprite(pg->mlx, "sprites/tile000.xpm");
	pg->sp.pl[3] = ft_new_sprite(pg->mlx, "sprites/tile004.xpm");
}
