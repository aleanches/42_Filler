/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:34:39 by Alexandr          #+#    #+#             */
/*   Updated: 2019/08/27 13:42:46 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef struct		s_fl
{
	int				player;
	int				map_w;
	int				map_h;
	int				*map;
	int				piece_w;
	int				piece_h;
	int				*piece;
	int				count_h;
}					t_fl;

#endif
