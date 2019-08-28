/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/28 12:49:45 by Alexandr         ###   ########.fr       */
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
	//int fd = open("input.txt", O_RDWR);
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
		{
			action = ft_fl_parse_piece(fl, &line);
			if (action == 60)
			{
				break;
			}	
		}
		
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


void	ft_fl_print_otimal(t_fl *fl, int player)
{
	t_cord optimal;
	t_cord cur;
	
	optimal.x = 0;
	optimal.y = 0;
	optimal.val = -1;
	cur.y = 0;
	while (cur.y < fl->map_h)
	{
		cur.x = 0;
		while (cur.x < fl->map_w)
		{
			cur.val = ft_fl_get_piece_sum(fl, cur, player);
			if (cur.val != -1 && (optimal.val == -1 || cur.val < optimal.val))
				optimal = cur;
			cur.x++;
		}
		cur.y++;
	}
	// ft_putnbr(optimal.y);
	// ft_putchar(' ');
	// ft_putnbr(optimal.x);
	// ft_putchar('\n');
	printf("%i %i\n", optimal.y, optimal.x);
}






int main()
{
    t_fl *fl;
	t_cord cord;

	char *line;

    ft_fl_init(&fl);

	// int fd = open("input.txt", O_RDWR);

	// while (get_next_line(0, &line) > 0)
	// {
	// 	dprintf(fd, "%s\n", line);
	// }


	while (42)
	{
		if (ft_fl_parse(&fl) == 10 || fl->piece_h != fl->count_h)
			ft_lm_put_error(&fl, 1);

		ft_fl_map_set_gradient(fl, fl->player == -1 ? -2 : -1);
		ft_fl_print_otimal(fl, fl->player);
	}





	// ft_fl_map_set_gradient(fl, -2);
	// ft_fl_print_otimal(fl, -1);
// 
// 					
// 				ft_putstr_fd(ft_itoa(fl->player) , fd);

	// ft_fl_map_set_gradient(fl, fl->player == -1 ? -2 : -1);
	// ft_fl_print_otimal(fl, fl->player);

	// printf("-------    %i\n", ft_fl_map_set_gradient(fl, fl->player == -1 ? -2 : -1));

	// int fd;
	// fd = open("input.txt", O_RDWR);
	// tmp_ft_print(fd, fl);

	// printf("-------    %i\n", ft_fl_get_piece_sum(fl, cord, fl->player));
	return (0);
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
