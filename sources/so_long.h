/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:52:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/14 23:40:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct	s_game 
{
	void	*mlx;
	void	*win;
}				t_game;

void	game_start(t_game *game);

#endif
