/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:30:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/06 19:41:12 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H
# include "so_long.h"

//walls
# define WALL "./sprites/wall-0.xpm"
# define WALL_L "./sprites/wall-l.xpm"
# define WALL_R "./sprites/wall-r.xpm"
# define WALL_LT "./sprites/wall-lt.xpm"
# define WALL_RT "./sprites/wall-rt.xpm"
# define WALL_LB "./sprites/wall-lb.xpm"
# define WALL_RB "./sprites/wall-rb.xpm"
# define WALL_INNER_0 "./sprites/wall-inner-0.xpm"
# define WALL_I_01 "./sprites/wall-inner-01.xpm"
# define WALL_INNER_2 "./sprites/wall-inner-2.xpm"
//floors
# define FLOOR0 "./sprites/floor-0.xpm"
# define FLOOR1 "./sprites/floor-1.xpm"
# define FLOOR2 "./sprites/floor-2.xpm"
# define FLOOR3 "./sprites/floor-3.xpm"
# define FLOOR4 "./sprites/floor-4.xpm"
//exit
# define EXIT_CLOSE "./sprites/floor-1.xpm"
# define EXIT_OPEN "./sprites/door-open.xpm"
//player
# define P_IDLE0 "./sprites/idle-01.xpm"
//collectibles
# define COLLECTIBLE "./sprites/collectible-0.xpm"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_sprite
{
	t_img	wall;
}		t_sprite;

#endif
