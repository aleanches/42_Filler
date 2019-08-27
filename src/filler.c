/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 00:25:01 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_filler.h"

void    ft_fl_init(t_fl **fl)
{
    if (((*fl) = (t_fl*)malloc(sizeof(t_fl))) == NULL)
		ft_lm_put_error(fl, 1);
    (*fl)->player = 0;
    (*fl)->map_w = 0;
    (*fl)->map_h = 0;
    (*fl)->map = NULL;
    (*fl)->piece_w = 0;
    (*fl)->piece_h = 0;
    (*fl)->piece = NULL;
    (*fl)->count_h = 0;
}

void		ft_lm_put_error(t_fl **fl, int ret_val)
{
	ft_putstr("ERROR\n");
	exit(ret_val);
}

int ft_fl_parse(t_fl **fl)
{
    char *line;
    int action;

    action = 10;
    while (get_next_line(0, &line) > 0)
    {
        if (action == 10)
			action = ft_fl_set_player(fl, &line);
        else if (action == 20)
			action = ft_fl_set_map_size(fl, &line);
		else if (action == 30)
			action = ft_fl_parse_map(fl, &line);
		else if (action == 40)
			action = ft_fl_set_piece_size(fl, &line);
		else if (action == 50)
			action = ft_fl_parse_piece(fl, &line);
		else if (action == 60)
			ft_lm_put_error(fl, ft_str_free(&line, 1));
		ft_str_free(&line, 0);
    }
	return (action);
}

int ft_fl_map_set_around_cord(t_fl *fl, t_cord cord, int val)
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

int ft_fl_map_set_around_val(t_fl *fl, int set_for, int set_val)
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

int ft_fl_map_set_gradient(t_fl *fl, int set_for)
{
	int set_val;
	
	set_val = 1;
	if (ft_fl_map_set_around_val(fl, set_for, set_val) == 0)
		return (0);
	while (ft_fl_map_set_around_val(fl, set_val, set_val + 1) > 0)
		set_val++;
	return (set_val);
}

int ft_fl_get_piece_sum(t_fl *fl, t_cord cord, int player)
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
				cur.val += fl->map[cur.y + cord.y][cur.x + cord.x];
			cur.x++;
		}
		cur.y++;
	}
	return (connects == 1 ? cur.val : -1);
}





int main()
{
    t_fl *fl;
	t_cord cord;

    ft_fl_init(&fl);

	

	cord.x = 2;
	cord.y = 1;


	if (ft_fl_parse(&fl) == 10 || fl->piece_h != fl->count_h)
		ft_lm_put_error(&fl, 1);

	printf("-------    %i\n", ft_fl_map_set_gradient(fl, -2));

	tmp_ft_print(fl);

	printf("-------    %i\n", ft_fl_get_piece_sum(fl, cord, -1));

}




// int main()
// {
//     char *line;
//     int fd;


//     line = NULL;

//     fd = open("input.txt", O_RDWR);

//     // printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//     // get_next_line(0, &line);
    
//     while (f_get_next_line(0, &line))
//     {
//         ft_putstr_fd(line, fd);
//         ft_putchar_fd('\n', fd);
//     }
//     return (0);
// }
