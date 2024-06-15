/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:52:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 19:58:01 by marsoare         ###   ########.fr       */
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

typedef struct	s_map
{
	void	**img;
	char	**map;
	int		lines;
	int		columns;
}				t_map;

void	game_start(t_game *game);
int		game_over(int keycode, t_game *game);

#endif
