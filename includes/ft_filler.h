/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:34:39 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/29 22:32:08 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

# define PLAYER_1 'O'
# define PLAYER_2 'X'
# define TOKEN_ACTIVE '*'
# define SMALL_MAP_SQ 650

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
	int				map_sq;
	int				**map;
	int				token_w;
	int				token_h;
	int				**token;
	int				count_h;
}					t_fl;

void	tmp_print_mtx(int fd, int **map, int w, int h);
void	tmp_ft_print(int fd, t_fl *fl);

int **ft_fl_mtx_new(int width, int height);

int ft_fl_set_player(t_fl **fl, char **line);
int ft_fl_set_map_size(t_fl **fl, char **line);
int ft_fl_set_token_size(t_fl **fl, char **line);
int ft_fl_parse_map(t_fl **fl, char **line);
int ft_fl_parse_token(t_fl **fl, char **line);
void		ft_lm_put_error(t_fl **fl, int ret_val);



int ft_fl_map_heat_set(t_fl *fl, int set_for);

void	ft_fl_make_move(t_fl *fl, int player);
int ft_fl_mtx_free(int ***map, int w, int h, int ret_val);

void	ft_fl_token_cut(t_fl **fl);


int ft_fl_mtx_clean(int **map, int w, int h, int ret_val);

void	ft_fl_token_cut(t_fl **fl);

#endif
