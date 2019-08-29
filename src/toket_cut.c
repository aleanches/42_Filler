/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toket_cut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:48:28 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/29 15:41:11 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

int 	ft_empty_row(int **map, int y, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (map[y][i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int 	ft_empty_col(int **map, int x, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (map[i][x] != 0)
			return (0);
		i++;
	}
	return (1);
}

t_cord	ft_fl_get_cut_cord_end(t_fl *fl)
{
	t_cord	e;

	e.x = fl->token_w - 1;
	while (e.x >= 0)
	{
		if (ft_empty_col(fl->token, e.x, fl->token_h) == 0)
			break ;
		e.x--;
	}
	e.y = fl->token_h - 1;
	while (e.y >= 0)
	{
		if (ft_empty_row(fl->token, e.y, fl->token_w) == 0)
			break ;
		e.y--;
	}
	return (e);
}

t_cord	ft_fl_get_cut_cord_start(t_fl *fl)
{
	t_cord	s;

	s.x = 0;
	while (s.x < fl->token_w)
	{
		if (ft_empty_col(fl->token, s.x, fl->token_h) == 0)
			break ;
		s.x++;
	}
	s.y = 0;
	while (s.y < fl->token_h)
	{
		if (ft_empty_row(fl->token, s.y, fl->token_w) == 0)
			break ;
		s.y++;
	}
	return (s);
}


void	ft_fl_token_cut(t_fl **fl)
{
	t_cord s;
	t_cord e;
	t_cord cur;
	int **new;

	s = ft_fl_get_cut_cord_start(*fl);
	e = ft_fl_get_cut_cord_end(*fl);
	cur.y = 0;

	if (s.x > e.x || s.y > e.y || (e.x - s.x + 1 == (*fl)->token_w && e.y - s.y + 1 == (*fl)->token_h))
		return ;
	new = ft_fl_mtx_new(((*fl)->token_w = e.x - s.x + 1), ((*fl)->token_h = e.y - s.y + 1));
	while (cur.y < (*fl)->token_h)
	{
		cur.x = 0;
		while (cur.x < (*fl)->token_w)
		{
			new[cur.y][cur.x] = (*fl)->token[cur.y + s.y][cur.x + s.x];
			cur.x++;
		}
		cur.y++;
	}
	(*fl)->token = new;
}
