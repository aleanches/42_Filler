/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:57:45 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 14:44:47 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

int ft_fl_set_player(t_fl **fl, char **line)
{
    char    **tmp;

    if ((tmp = ft_strsplit(*line, ' ')) == NULL || ft_array_len(tmp) < 3)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    if (ft_strcmp(tmp[2], "p1") == 0)
        (*fl)->player = -1;
    else if (ft_strcmp(tmp[2], "p2") == 0)
        (*fl)->player = -2;
    return (ft_array_free(&tmp, 20));
}

int ft_fl_set_map_size(t_fl **fl, char **line)
{
    char    **tmp;

    if ((tmp = ft_strsplit(*line, ' ')) == NULL
		|| ft_array_len(tmp) < 3 || ft_strcmp(tmp[0], "Plateau") != 0)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    (*fl)->map_h = ft_atoi(tmp[1]);
    (*fl)->map_w = ft_atoi(tmp[2]);
	if (((*fl)->map = ft_fl_mtx_new((*fl)->map_w, (*fl)->map_h)) == NULL)
		ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	(*fl)->count_h = 0;
    return (ft_array_free(&tmp, 30));
}

int ft_fl_set_piece_size(t_fl **fl, char **line)
{
    char    **tmp;

    if ((tmp = ft_strsplit(*line, ' ')) == NULL ||
		ft_array_len(tmp) < 3 || ft_strcmp(tmp[0], "Piece") != 0)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    (*fl)->piece_h = ft_atoi(tmp[1]);
    (*fl)->piece_w = ft_atoi(tmp[2]);
	if (((*fl)->piece = ft_fl_mtx_new((*fl)->map_w, (*fl)->map_h)) == NULL)
		ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	(*fl)->count_h = 0;
    return (ft_array_free(&tmp, 50));
}

int ft_fl_parse_map(t_fl **fl, char **line)
{
    int     i;
	int		start;
    if (ft_strlen(*line) > 3 && (*line)[0] == ' ' &&
		(*line)[1] == ' ' && (*line)[2] == ' ')
        return (30);
	if ((start = ft_get_char_i(*line, ' ')) == -1)
		ft_lm_put_error(fl, ft_str_free(line, 1));
	start++;
    if (ft_strlen(*line) - start != (*fl)->map_w)
		ft_lm_put_error(fl, ft_str_free(line, 1));
    i = 0;
    while (i < (*fl)->map_w)
    {
		if ((*line)[i + start] == PLAYER_1 ||
			(*line)[i + start] == ft_tolower(PLAYER_1))
			(*fl)->map[(*fl)->count_h][i] = -1;
		if ((*line)[i + start] == PLAYER_2 ||
			(*line)[i + start] == ft_tolower(PLAYER_2))
			(*fl)->map[(*fl)->count_h][i] = -2;
		i++;
    }
	(*fl)->count_h++;
	if ((*fl)->count_h == (*fl)->map_h)
		return (40);
	return (30);
}

int ft_fl_parse_piece(t_fl **fl, char **line)
{
    int     i;
	int		start;

    if (ft_strlen(*line) != (*fl)->piece_w)
		ft_lm_put_error(fl, ft_str_free(line, 1));
    i = 0;
    while (i < (*fl)->piece_w)
    {
		if ((*line)[i] == PIECE_ACTIVE)
			(*fl)->piece[(*fl)->count_h][i] = 1;
		i++;
    }
	(*fl)->count_h++;
	if ((*fl)->count_h == (*fl)->piece_h)
		return (60);
	return (50);
}
