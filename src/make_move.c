/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:45:01 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/30 15:01:06 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

static int ft_fl_get_token_sum(t_fl *fl, t_cord cord, int player)
{
    int		connects;
    t_cord	cur;
	
	connects = 0;
	cur.val = 0;
    if (cord.x + fl->token_w > fl->map_w || cord.y + fl->token_h > fl->map_h)
		return (-1);
	cur.y = 0;
	while (cur.y < fl->token_h)
	{
		cur.x = 0;
		while (cur.x < fl->token_w)
		{
			if (CORD(fl->token, cur) && CORD_OFS(fl->map, cord, cur) < 0 &&
				CORD_OFS(fl->map, cord, cur) == player)
				connects++;
			else if (CORD(fl->token, cur) && CORD_OFS(fl->map, cord, cur) < 0)
				return (-1);
			else if (CORD(fl->token, cur))
				cur.val += CORD_OFS(fl->map, cord, cur);
			cur.x++;
		}
		cur.y++;
	}
	return (connects == 1 ? cur.val : -1);
}

int	ft_fl_make_move(t_fl *fl, int player, int ret_val)
{
	t_cord optimal;
	t_cord cur;
	
	ft_bzero((void*)&optimal, sizeof(t_cord));
	optimal.val = -1;
	cur.y = 0;
	ft_fl_map_heat_set(fl, fl->player == -1 ? -2 : -1);
	while (cur.y < fl->map_h)
	{
		cur.x = 0;
		while (cur.x < fl->map_w)
		{
			cur.val = ft_fl_get_token_sum(fl, cur, player);
			if (cur.val != -1 && (optimal.val == -1 || cur.val < optimal.val))
				optimal = cur;
			cur.x++;
		}
		cur.y++;
	}
	ft_putnbr(optimal.y);
	ft_putchar(' ');
	ft_putnbr(optimal.x);
	ft_putchar('\n');
	return (ret_val);
}
