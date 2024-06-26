/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:41:10 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/26 14:43:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "./so_long.h"

typedef struct	s_sprite {
	t_list	*animations;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int		width;
	int		height;
	int		z_index;
}				t_sprite;

typedef	struct	sprite_slice {
	int x;
	int y;
	int width;
	int height;
}				sprite_slice;

/* Sprite */
t_sprite	new_sprite(char * name, char * file_path, t_win * win);
t_animation *	slice_sprite(t_sprite s, sprite_slice slice, int frames, int delay, enum entity e);
void	destroy_sprite(t_sprite s);

#endif