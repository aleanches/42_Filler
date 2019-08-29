/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:42:49 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/29 15:27:52 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

void	tmp_print_mtx(int fd, int **map, int w, int h)
{
	int ww = 0;
	int hh = 0;

	while (hh < h)
	{
		ww = 0;
		while (ww < w)
		{
			if (map[hh][ww] == -1)
				dprintf(fd, "| %c ", 'A');
			else if (map[hh][ww] == -2)
				dprintf(fd, "| %c ", 'X');
			else
				dprintf(fd, "| %i ", map[hh][ww]);
			ww++;
		}
		dprintf(fd, "|\n");
		hh++;
	}
}

void	tmp_ft_print(int fd, t_fl *fl)
{
	// dprintf(fd, "player = %i\n", fl->player);
	// dprintf(fd, "map_w = %i\n", fl->map_w);
	// dprintf(fd, "map_h = %i\n", fl->map_h);
	// dprintf(fd, "token_w = %i\n", fl->token_w);
	// dprintf(fd, "token_h = %i\n", fl->token_h);
	// dprintf(fd, "\n");
	// tmp_print_mtx(fd, fl->map, fl->map_w, fl->map_h);
	dprintf(fd, "\n");
	tmp_print_mtx(fd, fl->token, fl->token_w, fl->token_h);
}
