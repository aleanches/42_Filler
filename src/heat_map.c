/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:19:58 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/29 22:59:36 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

static int ft_fl_map_find_palyer_around(t_fl *fl, t_cord cord, int player)
{
	t_cord cur;
	
	cur.y = cord.y - 1;
	while (cur.y <= cord.y + 1)
	{
		if (cur.y >= 0 && cur.y < fl->map_h)
		{
			cur.x = cord.x - 1;
			while (cur.x <= cord.x + 1)
			{
				if (cur.x >= 0 && cur.x < fl->map_w &&
					!(cur.y == cord.y && cur.x == cord.x) &&
					fl->map[cur.y][cur.x] == player)
					return (1);
				cur.x++;
			}
		}
		cur.y++;
	}
	return (0);
}

static int ft_fl_map_set_cross_cord(t_fl *fl, t_cord cord, int val)
{
	int count;

	count = 0; 
	if (cord.y - 1 >= 0 && fl->map[cord.y - 1][cord.x] == 0)
	{
		count++;
		fl->map[cord.y - 1][cord.x] = val;
	}
	if (cord.y + 1 < fl->map_h && fl->map[cord.y + 1][cord.x] == 0)
	{
		count++;
		fl->map[cord.y + 1][cord.x] = val;
	}
	if (cord.x - 1 >= 0 && fl->map[cord.y][cord.x - 1] == 0)
	{
		count++;
		fl->map[cord.y][cord.x - 1] = val;
	}
	if (cord.x + 1 < fl->map_w && fl->map[cord.y][cord.x + 1] == 0)
	{
		count++;
		fl->map[cord.y][cord.x + 1] = val;
	}
	return (count);
}

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
			{
				if (fl->map_sq > SMALL_MAP_SQ &&
					ft_fl_map_find_palyer_around(fl, cur, fl->player) == 1)
					count += ft_fl_map_set_cross_cord(fl, cur, set_val);
				else
					count += ft_fl_map_set_around_cord(fl, cur, set_val);
			}
			cur.x++;
		}
		cur.y++;
	}
	return (count);
}

int ft_fl_map_heat_set(t_fl *fl, int set_for)
{
	int set_val;
	
	set_val = 1;
	if (ft_fl_map_set_around_val(fl, set_for, set_val) == 0)
		return (0);
	while (ft_fl_map_set_around_val(fl, set_val, set_val + 1) > 0)
		set_val++;
	return (set_val);
}
