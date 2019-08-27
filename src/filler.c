/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/27 20:14:22 by vsanta           ###   ########.fr       */
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

int main()
{
    t_fl *fl;

    ft_fl_init(&fl);


	if (ft_fl_parse(&fl) == 10)
		ft_lm_put_error(&fl, 1);

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
