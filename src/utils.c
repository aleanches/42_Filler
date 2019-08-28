/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:01:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 11:58:24 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

int **ft_fl_mtx_new(int width, int height)
{
	int i;
    int **mtx;
    
	i = 0;
    if ((mtx = (int**)malloc(sizeof(int*) * height)) == NULL)
        return (NULL);
	while (i < height)
	{
		if ((mtx[i] = (int*)malloc(sizeof(int) * width)) == NULL)
			return (NULL);	
		ft_bzero((void*)mtx[i], sizeof(int) * width);
		i++;
	}
	return (mtx);
}

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
	dprintf(fd, "player = %i\n", fl->player);
	dprintf(fd, "map_w = %i\n", fl->map_w);
	dprintf(fd, "map_h = %i\n", fl->map_h);
	dprintf(fd, "piece_w = %i\n", fl->piece_w);
	dprintf(fd, "piece_h = %i\n", fl->piece_h);
	dprintf(fd, "\n");
	tmp_print_mtx(fd, fl->map, fl->map_w, fl->map_h);
	dprintf(fd, "\n");
	tmp_print_mtx(fd, fl->piece, fl->piece_w, fl->piece_h);
}