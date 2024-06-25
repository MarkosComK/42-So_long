/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/25 14:11:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./colors.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>

# define BOOL int
# define true 1
# define false 0

# define SIZE 32

typedef struct	s_map
{
	char	**str;
	int		rows;
	int		cols;
	int		width;
	int		height;
	int		player;
	int		enemies;
	int		collectables;
	int		exits;
}				t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_entity
{
	t_point		pos;
}				t_entity;

typedef struct  s_game
{
	void		*mlx;
	void		*win;
    t_map		map;
	t_entity	player;
}               t_game;

BOOL	validate_ber(char *path);
void	set_game(char *map_name);
void    set_map(t_game *game, char *map_path);
void	set_player_pos(t_game *game);
int		key_press(int keycode, t_game *g);
//MAP CHECKERS
void	validate_map(t_game *game);
// UTILITIES TO DELETE LATER
void	print_map(t_game *game);
int     error_msg(char *msg);

#endif