/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/27 21:13:21 by vsanta           ###   ########.fr       */
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

int ft_fl_map_set_around_one(t_fl *fl, t_cord cord, int val)
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
				if (cur.x >= 0 && cur.x < fl->map_w && fl->map[cur.y][cur.x] == 0 && !(cur.y == cord.y && cur.x == cord.x))
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

int ft_fl_map_set_around_all(t_fl *fl, int set_for, int set_val)
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
				count += ft_fl_map_set_around_one(fl, cur, set_val);
			cur.x++;
		}
		cur.y++;
	}
	return (count);
}

int ft_fl_map_set_map(t_fl *fl)
{
	int set_val;
	
	set_val = 1;
	if (ft_fl_map_set_around_all(fl, -2, set_val) == 0)
		return (0);
	while (ft_fl_map_set_around_all(fl, set_val, set_val + 1) > 0)
		set_val++;
	return (set_val);
}


int main()
{
    t_fl *fl;

    ft_fl_init(&fl);


	if (ft_fl_parse(&fl) == 10)
		ft_lm_put_error(&fl, 1);

	printf("-------    %i\n", ft_fl_map_set_map(fl));

	tmp_ft_print(fl);



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
