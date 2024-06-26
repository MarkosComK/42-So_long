/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:34:57 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/26 14:40:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include "../libraries/libft/libft.h"

enum entity {
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_animation {
	t_list	*frames;
	int		width;
	int		height;
	int		delay;			// How many fps it takes to change animation
	int		_tmp_delay;		// Delay Iterator
	int		current_frame_num;	// Which frame is selected
	long int	last_updated;		// When was the last update
	long int	frame_count;		// The frame count
	enum entity	entity;
}		t_animation;

#endif