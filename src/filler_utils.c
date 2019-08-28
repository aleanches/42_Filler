/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:45:01 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 21:33:08 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

static int ft_fl_map_set_around_cord(t_fl *fl, t_cord cord, int val)
{
	int count;
	t_cord cur;
	
	count = 0;
	cur.y = cord.y - 1;
	while (cur.y <= cord.y + 1)
	{
		if (cur.y >= 0 && cur.y < fl->map_h)
		{
			cur.x = cord.x - 1;
			while (cur.x <= cord.x + 1)
			{
				if (cur.x >= 0 && cur.x < fl->map_w &&
					fl->map[cur.y][cur.x] == 0 &&
					!(cur.y == cord.y && cur.x == cord.x))
				{
					count++;
					fl->map[cur.y][cur.x] = val;
				}
				cur.x++;
			}
		}
		cur.y++;
	}
	return (count);
}

static int ft_fl_map_set_around_val(t_fl *fl, int set_for, int set_val)
{
	int count;
	t_cord cur;

	count = 0;
	cur.y = 0;
	while (cur.y < fl->map_h)
	{
		cur.x = 0;
		while (cur.x < fl->map_w)
		{
			if (fl->map[cur.y][cur.x] == set_for)
				count += ft_fl_map_set_around_cord(fl, cur, set_val);
			cur.x++;
		}
		cur.y++;
	}
	return (count);
}

static int ft_fl_map_set_gradient(t_fl *fl, int set_for)
{
	int set_val;
	
	set_val = 1;
	if (ft_fl_map_set_around_val(fl, set_for, set_val) == 0)
		return (0);
	while (ft_fl_map_set_around_val(fl, set_val, set_val + 1) > 0)
		set_val++;
	return (set_val);
}

static int ft_fl_get_piece_sum(t_fl *fl, t_cord cord, int player)
{
    int		connects;
    t_cord	cur;
	
	connects = 0;
	cur.val = 0;
    if (cord.x + fl->piece_w > fl->map_w || cord.y + fl->piece_h > fl->map_h)
		return (-1);
	cur.y = 0;
	while (cur.y < fl->piece_h)
	{
		cur.x = 0;
		while (cur.x < fl->piece_w)
		{
			if (MAP(fl->piece, cur) && MAPS(fl->map, cur, cord) < 0 &&
				MAPS(fl->map, cur, cord) == player)
				connects++;
			else if (MAP(fl->piece, cur) && MAPS(fl->map, cur, cord) < 0)
				return (-1);
			else if (MAP(fl->piece, cur))
				cur.val += MAPS(fl->map, cur, cord);
			cur.x++;
		}
		cur.y++;
	}
	return (connects == 1 ? cur.val : -1);
}

void	ft_fl_print_otimal(t_fl *fl, int player)
{
	t_cord optimal;
	t_cord cur;
	
	optimal.x = 0;
	optimal.y = 0;
	optimal.val = -1;
	cur.y = 0;
	ft_fl_map_set_gradient(fl, fl->player == -1 ? -2 : -1);
	while (cur.y < fl->map_h)
	{
		cur.x = 0;
		while (cur.x < fl->map_w)
		{
			cur.val = ft_fl_get_piece_sum(fl, cur, player);
			if (cur.val != -1 && (optimal.val == -1 || cur.val <= optimal.val))
				optimal = cur;
			cur.x++;
		}
		cur.y++;
	}
	ft_putnbr(optimal.y);
	ft_putchar(' ');
	ft_putnbr(optimal.x);
	ft_putchar('\n');
}
