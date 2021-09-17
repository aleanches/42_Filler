/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:34:39 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/30 18:15:00 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

# define PLAYER_1 'O'
# define PLAYER_2 'X'
# define TOKEN_ACTIVE '*'
# define SMALL_MAP_SQ 650

# define CORD(MAP, CORD) MAP[CORD.y][CORD.x]
# define CORD_OFS(MAP, CORD, OFS) MAP[CORD.y + OFS.y][CORD.x + OFS.x]

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

void				put_error(t_fl **fl, int ret_val);
int					map_heat_set(t_fl *fl, int set_for);
int					make_move(t_fl *fl, int player, int ret_val);
int					mtx_free(int ***map, int w, int h, int ret_val);
int					mtx_clean(int **map, int w, int h, int ret_val);
int					**mtx_new(int width, int height);
int					set_player(t_fl **fl, char **line);
int					set_map_size(t_fl **fl, char **line);
int					set_token_size(t_fl **fl, char **line);
int					parse_map(t_fl **fl, char **line);
int					parse_token(t_fl **fl, char **line);

#endif
