/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:34:39 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/28 21:20:37 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

# define PLAYER_1 'O'
# define PLAYER_2 'X'
# define PIECE_ACTIVE '*'

# define MAP(MAP, A) MAP[A.y][A.x]
# define MAPS(MAP, A, B) MAP[A.y + B.y][A.x + B.x]

typedef struct		s_cord
{
	int				x;
	int				y;
	int				val;
}					t_cord;

typedef struct		s_fl
{
	char			*line;
	int				action;
	int				player;
	int				map_w;
	int				map_h;
	int				**map;
	int				piece_w;
	int				piece_h;
	int				**piece;
	int				count_h;
}					t_fl;

void	tmp_print_mtx(int fd, int **map, int w, int h);
void	tmp_ft_print(int fd, t_fl *fl);

int **ft_fl_mtx_new(int width, int height);

int ft_fl_set_player(t_fl **fl, char **line);
int ft_fl_set_map_size(t_fl **fl, char **line);
int ft_fl_set_piece_size(t_fl **fl, char **line);
int ft_fl_parse_map(t_fl **fl, char **line);
int ft_fl_parse_piece(t_fl **fl, char **line);
void		ft_lm_put_error(t_fl **fl, int ret_val);




void	ft_fl_print_otimal(t_fl *fl, int player);
int ft_fl_mtx_free(int ***map, int w, int h, int ret_val);


int ft_fl_mtx_clean(int **map, int w, int h, int ret_val);

#endif
