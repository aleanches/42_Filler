/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:57:45 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/30 18:28:22 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	ft_fl_set_player(t_fl **fl, char **line)
{
	char	**tmp;

	if ((tmp = ft_strsplit(*line, ' ')) == NULL || ft_array_len(tmp) < 3)
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	if (ft_strcmp(tmp[2], "p1") == 0)
		(*fl)->player = -1;
	else if (ft_strcmp(tmp[2], "p2") == 0)
		(*fl)->player = -2;
	else
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	return (ft_array_free(&tmp, 20));
}

int	ft_fl_set_map_size(t_fl **fl, char **line)
{
	char	**tmp;

	(*fl)->count_h = 0;
	if ((*fl)->map != NULL)
		return (ft_fl_mtx_clean((*fl)->map, (*fl)->map_w, (*fl)->map_h, 30));
	if ((tmp = ft_strsplit(*line, ' ')) == NULL
		|| ft_array_len(tmp) < 3 || ft_strcmp(tmp[0], "Plateau") != 0)
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	(*fl)->map_w = ft_atoi(tmp[2]);
	(*fl)->map_h = ft_atoi(tmp[1]);
	(*fl)->map_sq = (*fl)->map_w * (*fl)->map_h;
	if (((*fl)->map = ft_fl_mtx_new((*fl)->map_w, (*fl)->map_h)) == NULL)
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	return (ft_array_free(&tmp, 30));
}

int	ft_fl_set_token_size(t_fl **fl, char **line)
{
	char	**tmp;

	(*fl)->count_h = 0;
	if ((tmp = ft_strsplit(*line, ' ')) == NULL ||
		ft_array_len(tmp) < 3 || ft_strcmp(tmp[0], "Piece") != 0)
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	ft_fl_mtx_free(&((*fl)->token), (*fl)->token_w, (*fl)->token_h, 0);
	(*fl)->token_w = ft_atoi(tmp[2]);
	(*fl)->token_h = ft_atoi(tmp[1]);
	if (((*fl)->token = ft_fl_mtx_new((*fl)->token_w, (*fl)->token_h)) == NULL)
		ft_fl_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
	return (ft_array_free(&tmp, 50));
}

int	ft_fl_parse_map(t_fl **fl, char **line)
{
	int	i;
	int	start;

	if (ft_strncmp(*line, "   ", 3) == 0)
		return (30);
	if ((start = ft_get_char_i(*line, ' ')) == -1)
		ft_fl_put_error(fl, ft_str_free(line, 1));
	start++;
	if ((int)ft_strlen(*line) - start != (*fl)->map_w)
		ft_fl_put_error(fl, ft_str_free(line, 1));
	i = 0;
	while (i < (*fl)->map_w)
	{
		if ((*line)[i + start] == PLAYER_1 ||
			(*line)[i + start] == ft_tolower(PLAYER_1))
			(*fl)->map[(*fl)->count_h][i] = -1;
		else if ((*line)[i + start] == PLAYER_2 ||
			(*line)[i + start] == ft_tolower(PLAYER_2))
			(*fl)->map[(*fl)->count_h][i] = -2;
		i++;
	}
	(*fl)->count_h++;
	if ((*fl)->count_h == (*fl)->map_h)
		return (40);
	return (30);
}

int	ft_fl_parse_token(t_fl **fl, char **line)
{
	int	i;

	if ((int)ft_strlen(*line) != (*fl)->token_w)
		ft_fl_put_error(fl, ft_str_free(line, 1));
	i = 0;
	while (i < (*fl)->token_w)
	{
		if ((*line)[i] == TOKEN_ACTIVE)
			(*fl)->token[(*fl)->count_h][i] = 1;
		i++;
	}
	(*fl)->count_h++;
	if ((*fl)->count_h == (*fl)->token_h)
		return (60);
	return (50);
}
