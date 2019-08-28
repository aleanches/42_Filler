/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:01:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 21:20:32 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

int ft_fl_mtx_free(int ***map, int w, int h, int ret_val)
{
	int  y;

	y = 0;
	while (map && *map && y < h)
	{
		ft_bzero((void*)(*map)[y], sizeof(int) * w);
		free((*map)[y]);
		(*map)[y] = NULL;
		y++;
	}
	if (map && *map)
		free(*map);
	return (ret_val);
}

int ft_fl_mtx_clean(int **map, int w, int h, int ret_val)
{
	int  y;

	y = 0;
	while (map && *map && y < h)
	{
		ft_bzero((void*)map[y], sizeof(int) * w);
		y++;
	}
	return (ret_val);
}

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
