/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:19:14 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 00:06:32 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	main_args_parsing(int ac, char **av);
int	ft_input(int key, t_prog *pg);
int	ft_release(int key, t_prog *pg);

int	main(int ac, char **av)
{
	int		fd;
	t_prog	pg;

	if (main_args_parsing(ac, av) != 0)
		return (1);
	ft_bzero(&pg, sizeof(t_prog));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFailed to open the map\n\n"));
	pg.map.tab = ft_readmap(fd);
	close(fd);
	if (!pg.map.tab)
		ft_close(1);
	pg = ft_mapinit(pg);
	pg.mlx = mlx_init();
	pg.wdw = ft_new_window(pg.mlx, 1000, 1000, "Pokemon : Gotta catch em all");
	import_all_sprites(&pg);
	mlx_hook(pg.wdw.ref, 2, 0, ft_input, &pg);
	mlx_hook(pg.wdw.ref, 3, 0, ft_release, &pg);
	mlx_hook(pg.wdw.ref, 17, 0, ft_close, 0);
	mlx_loop_hook(pg.mlx, *ft_update, &pg);
	mlx_loop(pg.mlx);
}
