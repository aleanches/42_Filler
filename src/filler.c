/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/30 18:54:04 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void	init(t_fl **fl)
{
	if (((*fl) = (t_fl*)malloc(sizeof(t_fl))) == NULL)
		put_error(fl, 1);
	(*fl)->line = NULL;
	(*fl)->action = 10;
	(*fl)->player = 0;
	(*fl)->map_w = 0;
	(*fl)->map_h = 0;
	(*fl)->map_sq = 0;
	(*fl)->map = NULL;
	(*fl)->token_w = 0;
	(*fl)->token_h = 0;
	(*fl)->token = NULL;
	(*fl)->count_h = 0;
}

static int	fl_free(t_fl **fl, int ret_val)
{
	mtx_free(&((*fl)->map), (*fl)->map_w, (*fl)->map_h, 0);
	mtx_free(&((*fl)->token), (*fl)->token_w, (*fl)->token_h, 0);
	if (fl && *fl)
	{
		free(*fl);
		*fl = NULL;
	}
	return (ret_val);
}

void		put_error(t_fl **fl, int ret_val)
{
	ft_putstr("ERROR\n");
	exit(fl_free(fl, ret_val));
}

int			main(void)
{
	t_fl *fl;

	init(&fl);
	while (f_get_next_line(0, &(fl->line)) > 0)
	{
		if (fl->action == 10)
			fl->action = set_player(&fl, &(fl->line));
		else if (fl->action == 20)
			fl->action = set_map_size(&fl, &(fl->line));
		else if (fl->action == 30)
			fl->action = parse_map(&fl, &(fl->line));
		else if (fl->action == 40)
			fl->action = set_token_size(&fl, &(fl->line));
		else if (fl->action == 50)
			fl->action = parse_token(&fl, &(fl->line));
		if (fl->action == 60)
			fl->action = make_move(fl, fl->player, 20);
		ft_str_free(&(fl->line), 0);
	}
	return (fl_free(&fl, 0));
}
