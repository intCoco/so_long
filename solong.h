/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:33 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/06 21:12:51 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define SQ_L 42

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_obj {
	int	p_nb;
	int	e_nb;
	int	c_nb;
	int	m_nb;
}				t_obj;

typedef struct s_error {
	int	rect_check;
	int	walls_check;
	int	char_check;
	int	nr_c;
	int	nr_e;
	int	fd_er;
}				t_error;

typedef struct s_map {
	char		**tab;
	char		**tab2;
	t_vector	size;
	t_obj		obj;
	t_error		error;
}				t_map;

/* A pointer to the wdw and its size */
typedef struct s_wdw {
	void		*ref;
	t_vector	size;
}				t_wdw;

/* all info needed for an image */
typedef struct s_image {
	void		*ref;
	t_vector	size;
}				t_image;

typedef struct s_char {
	t_vector	pos;
	int			d;
	t_vector	fcg;
	int			count;
	int			mov;
}				t_char;

typedef struct s_sprites {
	t_image		pl[2][3][4];
	t_image		pc[4];
	t_image		fpl[4];
	t_image		fpl_sav;
	t_image		en[3][4];
	t_image		bg;
	t_image		nb[10];
	t_image		pkb;
	t_image		wall;
	t_image		ground;
	t_image		block[8];
	t_image		flower[6];
	t_image		intro[7];
	t_image		anim[12];
	t_image		anim2[2];
	t_image		excl;
	t_image		dia_box[2];
	t_image		dk[4];
	t_image		fpl_dia;
	t_image		arw;
	t_image		pkm[3][3][3][4];
	t_image		pkm_anim[24];
	t_image		pkm_sel[3];
	t_image		crs[3];
	t_image		bol_crs;
}				t_sprites;

typedef struct s_prog {
	void		*mlx;
	t_wdw		wdw;
	t_map		map;
	t_sprites	sp;
	t_char		ex;
	t_char		pl;
	t_char		en;
	t_char		pkm;
	int			ret;
	int			excl_b;
	int			pick;
	int			begin;
	int			end;
	int			timer;
	int			timer2;
	int			split;
	int			tanim;
	int			run;
	int			i;
	int			frame;
	int			lkey;
	int			pkm_nb;
	int			pkm_ev;
	int			cur_sel;
	int			select;
	int			bol;
}				t_prog;

char	**ft_readmap(int fd);
t_prog	ft_mapinit(t_prog prog);
int		ft_check_error(t_prog prog);
int		ft_input(int key, t_prog *prog);
int		ft_update(t_prog *prog);
void	draw_wall(t_prog prog);
void	print_game(t_prog prog);
void	ft_find_p(t_prog *prog);
void	ft_print_pathfinding(t_map map);
t_prog	ft_encheck(t_prog prog);
t_prog	ft_interac_en(t_prog prog, t_vector *cd);
int		ft_close(t_map *map, char *err_txt);

t_image	ft_new_sprite(void *mlx, char *path);
t_wdw	ft_new_window(void *mlx, int widht, int height, char *name);

void	import_all_sprites(t_prog *prog);

#endif
