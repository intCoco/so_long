/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:40:21 by chuchard          #+#    #+#             */
/*   Updated: 2023/01/04 18:46:26 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	return (img);
}

t_wdw	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_wdw	wdw;

	wdw.ref = mlx_new_window(mlx, widht, height, name);
	wdw.size.x = widht;
	wdw.size.y = height;
	mlx_hook(wdw.ref, 17, 0, ft_close, 0);
	return (wdw);
}
