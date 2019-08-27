/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:01:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/27 19:33:59 by vsanta           ###   ########.fr       */
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

void	tmp_print_mtx(int **map, int w, int h)
{
	int ww = 0;
	int hh = 0;

	while (hh < h)
	{
		ww = 0;
		while (ww < w)
		{
			printf("%i ", map[hh][ww]);
			ww++;
		}
		printf("\n");
		hh++;
	}
}

void	tmp_ft_print(t_fl *fl)
{
	printf("player = %i\n",	fl->player);
	printf("map_w = %i\n", fl->map_w);
	printf("map_h = %i\n", fl->map_h);
	printf("piece_w = %i\n", fl->piece_w);
	printf("piece_h = %i\n", fl->piece_h);
	printf("\n");
	tmp_print_mtx(fl->map, fl->map_w, fl->map_h);
	printf("\n");
	tmp_print_mtx(fl->piece, fl->piece_w, fl->piece_h);
}