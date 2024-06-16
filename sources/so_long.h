/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:52:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 14:55:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include <fcntl.h>
# include <X11/keysym.h>

//IMAGE ASSETS
# define PLAYER_IDLE_0 "./assets/character/player_idle_0.xpm"
# define GROUND_0 "./assets/ground/ground_0.xpm"

typedef struct	s_map
{
	void	**img;
	char	**map;
	int		lines;
	int		columns;
	int		width;
	int		height;
}				t_map;

typedef struct	s_game 
{
	void	*mlx;
	void	*win;
	void	**img;
  int   player_x;
  int   player_y;
	t_map	map;
}				t_game;

void	game_start(char *path, t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		handle_key(int keycode, t_game *game);

#endif
