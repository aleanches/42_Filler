/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:39:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/26 21:20:12 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"


int main()
{
    char *line;
    int fd;


    line = NULL;

    fd = open("input.txt", O_RDWR);

    while (f_get_next_line(0, &line))
    {
        ft_putstr_fd(line, fd);
        ft_putchar_fd('\n', fd);
    }
    return (0);
}
