/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:30:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 14:21:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H
# include "so_long.h"

# define WALL "../sprites/wall-0.xpm"
# define FLOOR0 "../sprites/floor-0.xpm"
# define FLOOR1 "../sprites/floor-1.xpm"
# define FLOOR2 "../sprites/floor-2.xpm"

typedef struct s_img
{
	void	*mlx;
	void	*win;
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