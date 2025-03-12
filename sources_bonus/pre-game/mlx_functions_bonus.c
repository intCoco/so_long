/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:40:21 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/13 03:35:41 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (img.ref == 0)
	{
		ft_printf("Sprite import error, please make sure no file is missing\n");
		exit(1);
	}
	img.data = mlx_get_data_addr(img.ref, &img.bpp, &img.size_line, &img.endian);
	return (img);
}

t_wdw	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_wdw	wdw;

	wdw.ref = mlx_new_window(mlx, widht, height, name);
	wdw.size.x = widht;
	wdw.size.y = height;
	return (wdw);
}
