/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 21:18:08 by marsoare         ###   ########.fr       */
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
	t_img		*world;
}               t_game;

/*
 * checkers/
 */
//validate_ber.c
BOOL	validate_ber(char *path);

//validate_map.c
void	validate_map(t_game *game);
int	map_retangular(t_map map);
int	map_components(t_map map);
int	map_walls(t_map map);

/*
 * sprites/
 */
//create_sprites.c
t_img	*create_sprite(t_game *game, char *sprite_path);
void	create_map(t_game *game);
char	*get_sprite_path(t_game *game, char c, int x, int y);
void	create_world(t_img *sprite, t_game *game, int posx, int posy);

//handle_pixel.c
void	put_pixel(t_img *sprite, int x, int y, int color);
unsigned int	get_color_in_pixel(t_img *sprite, int x, int y);

/*
 * utils/
 */
int     error_msg(char *msg);
void	print_map(t_game *game);

//end_game.c
void	quit(t_game *game);

//handle_keys.c
int	key_press(int keycode, t_game *g);

//player.c
void	set_player_pos(t_game *game);

//start_game.c
void	start_game(char	*map_path);
void	set_game(t_game *game, char *map_path);

//start_map.c
void	fill_map(t_game *game);
void	start_world(t_game *game);
void    set_map(t_game *game, char *map_path);

#endif
