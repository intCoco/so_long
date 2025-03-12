/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:46:52 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/13 07:22:29 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

unsigned int alpha_blend(unsigned int dst, unsigned int src, unsigned int alpha)
{
    unsigned int dst_r = (dst >> 16) & 0xFF;  // Extraire le composant rouge du pixel de fond
    unsigned int dst_g = (dst >> 8) & 0xFF;   // Extraire le composant vert du pixel de fond
    unsigned int dst_b = dst & 0xFF;          // Extraire le composant bleu du pixel de fond

    unsigned int src_r = (src >> 16) & 0xFF;  // Extraire le composant rouge du pixel du sprite
    unsigned int src_g = (src >> 8) & 0xFF;   // Extraire le composant vert du pixel du sprite
    unsigned int src_b = src & 0xFF;          // Extraire le composant bleu du pixel du sprite

    // Calcul de la nouvelle couleur avec la fusion alpha
    unsigned int r = (unsigned int)((alpha * src_r + (255 - alpha) * dst_r) / 255);
    unsigned int g = (unsigned int)((alpha * src_g + (255 - alpha) * dst_g) / 255);
    unsigned int b = (unsigned int)((alpha * src_b + (255 - alpha) * dst_b) / 255);

    // Retourner la couleur combinée dans le format ARGB
    return (alpha << 24) | (r << 16) | (g << 8) | b;  // Réassembler la couleur avec l'alpha
}

void put_sprite_to_image(t_image *img, t_image *sprite, int x, int y)
{
    unsigned int *img_data;
    unsigned int *sprite_data;
    int img_width, img_height;
    int sprite_width, sprite_height;
    int i, j;
    unsigned int dst_color, src_color, blended_color;
    unsigned int alpha;

    img_data = (unsigned int *)img->data;
    img_width = 1000;  // Largeur de l'image principale
    img_height = 1000;  // Hauteur de l'image principale
    sprite_data = (unsigned int *)sprite->data;
    sprite_width = sprite->size.x;  // Largeur du sprite
    sprite_height = sprite->size.y; // Hauteur du sprite
     int start_x = (x < 0) ? -x : 0; // Si x est négatif, on commence plus loin dans le sprite
    int start_y = (y < 0) ? -y : 0; // Idem pour y
    int end_x = (x + sprite_width > img_width) ? img_width - x : sprite_width;
    int end_y = (y + sprite_height > img_height) ? img_height - y : sprite_height;
    for (i = start_x; i < end_x; i++)
    {
        for (j = start_y; j < end_y; j++)
        {
            src_color = sprite_data[j * sprite_width + i];
            alpha = (src_color >> 24) & 0xFF;  // Extraire la composante alpha (0-255)
			alpha = 255 - alpha;
            if (alpha == 0)
                continue;
            dst_color = img_data[(y + j) * img_width + (x + i)];
			if (alpha == 255)
			{
				img_data[(y + j) * img_width + (x + i)] = src_color;
				continue;
			}
            blended_color = alpha_blend(dst_color, src_color, alpha);
            img_data[(y + j) * img_width + (x + i)] = blended_color;
        }
    }
}

void	print_im(t_prog pg, t_image im, int x, int y)
{
	put_sprite_to_image(&pg.dest, &im, x - (im.size.x / 2), y - im.size.y);
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
