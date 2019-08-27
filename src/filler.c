/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/27 13:52:58 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// $$$ exec p1 : [./test]
// Plateau 15 17:
//     01234567890123456
// 000 .................
// 001 .................
// 002 .................
// 003 .................
// 004 .................
// 005 .................
// 006 .................
// 007 .................
// 008 ..O..............
// 009 .................
// 010 .................
// 011 .................
// 012 ..............X..
// 013 .................
// 014 .................
// Piece 1 2:
// **

# include "ft_filler.h"


	// int				player;
	// int				map_w;
	// int				map_h;
	// int				*map;
	// int				piece_w;
	// int				piece_h;
	// int				*piece;

void    ft_fl_init(t_fl **fl)
{
    (*fl) = malloc(sizeof(t_fl));
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

int ft_fl_parse_player(t_fl **fl, char **line)
{
    char    **tmp;

    if ((tmp = ft_strsplit(*line, ' ')) == NULL || ft_array_len(tmp) < 3)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    if (ft_strcmp(tmp[2], "p1") == 0)
        (*fl)->player = 1;
    else if (ft_strcmp(tmp[2], "p2") == 0)
        (*fl)->player = 2;
    return (ft_array_free(&tmp, 20));
}

int ft_fl_parse_map_size(t_fl **fl, char **line)
{
    char    **tmp;

    if ((tmp = ft_strsplit(*line, ' ')) == NULL || ft_array_len(tmp) < 3 || ft_strcmp(tmp[0], "Plateau") != 0)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    (*fl)->piece_h = ft_atoi(tmp[1]);
    (*fl)->piece_w = ft_atoi(tmp[2]);
    return (ft_array_free(&tmp, 30));
}

int ft_fl_parse_map(t_fl **fl, char **line)
{
    char    **tmp;
    int     i;
    if (ft_strlen(*line) > 3 && (*line)[0] == ' ' && (*line)[1] == ' ' && (*line)[2] == ' ')
        return (30);
    if ((tmp = ft_strsplit(*line, ' ')) == NULL || ft_array_len(tmp) < (*fl)->map_w + 1)
        ft_lm_put_error(fl, ft_array_free(&tmp, ft_str_free(line, 1)));
    i = 1;
    while (i < (*fl)->map_w + 1)
    {
        if (tmp[i] == '.')
    }
    
}

int ft_fl_parse(t_fl **fl)
{
    char *line;
    int action;
    
    line = NULL;
    action = 10;
    while (get_next_line(0, &line) > 0)
    {
        if (action == 10)
            action = ft_fl_parse_player(&fl, &line);
        else if (action == 20)
            action = ft_fl_parse_map_size(&fl, &line);
    }

}




int main()
{
    t_fl *fl;

    ft_fl_init(&fl);




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
