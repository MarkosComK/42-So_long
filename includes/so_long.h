/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 13:31:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./colors.h"
# include "../libraries/libft/libft.h"
# include "./sprites.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>

# define BOOL int
# define true 1
# define false 0

# define SZ 32

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_tile
{
	char	type;
	char	*sprite_path;
	t_pos	pos;
}		t_tile;

typedef struct	s_map
{
	char		**data;
	int		rows;
	int		cols;
	int		width;
	int		height;
	int		collectables;
	int		player;
	int		exits;
	t_tile		**tiles;
}				t_map;


typedef struct s_entity
{
	t_pos		pos;
}				t_entity;

typedef struct  s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_entity	player;
}               t_game;

BOOL	validate_ber(char *path);
void	set_game(t_game *game, char *map_name);
void	start_game(char	*map_path);
void    set_map(t_game *game, char *map_path);
void	set_player_pos(t_game *game);
void	quit(t_game *game);
int		key_press(int keycode, t_game *g);
t_img   new_file_img(char *path, t_game *game);
//MAP CHECKERS
void	validate_map(t_game *game);
// UTILITIES TO DELETE LATER
void	print_map(t_game *game);
int     error_msg(char *msg);

#endif
