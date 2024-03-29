/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:33 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/14 17:41:27 by chuchard         ###   ########.fr       */
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
	t_image		pl[4];
	t_image		fpl;
	t_image		pkb;
	t_image		ground;
	t_image		wall;
	t_image		intro;
}				t_sprites;

typedef struct s_pg {
	void		*mlx;
	t_wdw		wdw;
	t_map		map;
	t_sprites	sp;
	t_char		ex;
	t_char		pl;
	int			hold[4];	//input/release
}				t_prog;

char		**ft_readmap(int fd);
t_prog		ft_mapinit(t_prog pg);
int			ft_check_error(t_prog pg);
int			ft_input(int key, t_prog *pg);
int			ft_update(t_prog *pg);
void		print_game(t_prog *pg);
int			ft_close(int merror);
void		ft_pick(t_prog *pg);
void		ft_fcg_cood(t_char *chr);
void		ft_dir_input(int key, t_char *chr);
int			ft_move(int key, t_char *chr);
void		player_behavior(t_prog *pg);
void		ft_check_map(t_prog *pg);
void		ft_check_pathfinding(t_map *map);
void		ft_print_error(t_map map);
void		ft_pathfinding(t_map *map, int x, int y);
int			main_args_parsing(int ac, char **av);
int			ft_input(int key, t_prog *pg);
int			ft_release(int key, t_prog *pg);

t_vector	ad(int x, int y);
void		print_im(t_prog pg, t_image im, int x, int y);
void		print_mov(t_prog pg, t_image im, t_vector cd, t_vector ad);

t_image		ft_new_sprite(void *mlx, char *path);
t_wdw		ft_new_window(void *mlx, int widht, int height, char *name);

void		import_all_sprites(t_prog *pg);

#endif
