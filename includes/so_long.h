/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 19:25:31 by marsoare         ###   ########.fr       */
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
	t_pos		s_pos;
	t_pos		d_pos;
	t_img		*sprite;
	int			current_sprite;
	char		*sprite_idle[0];
}				t_entity;

typedef struct s_bottle
{
	t_pos		pos;
	t_img		*sprite;
	struct s_bottle	*next;
}				t_bottle;
typedef struct  s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_entity	player;
	t_img		*world;
	t_bottle	*bottle;
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
 * collectibes/
 */
//collectibles.c
void	init_collectibles(t_game *game);
//list_utils.c
t_bottle	*ft_bottlelast(t_bottle *lst);
t_bottle	*bottle_add(t_bottle *node, int x, int y);
t_bottle	*bottle_push_tail(t_bottle *stack, int x, int y);
t_bottle	*bottle_create(int x, int y);

/*
 * game_over/
 */
//frees.c
void	destroy_sprite(t_img **sprite, void *mlx);
void	free_map(t_map map);
void	free_tiles(t_map map);
void	free_bottles(t_bottle *bottles);

/*
 * player/
 */
//player.c
void	init_player(t_game *game);
void	load_player_sprite(t_game *game);
void	set_player_pos(t_game *game);
void	create_player(t_img *sprite, t_game *game, int posx, int posy);

//quit.c
void	quit(t_game *game);

/*
 * renderization/
 */
//draw.c
void	draw_player(t_game *game);
void	draw_map(t_game *game);
void	draw_collectibles(t_game *game);
void	draw_bottles(t_game *game);

//renderization.c
void	render_game(t_game *game);
void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_collectibles(t_game *game);

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
void	print_player_struct(t_entity player);
//randomizer.c
char	*randomize_floor(int x, int y, t_map map);
//utils.c
int	count_lines(char *map_path);

//end_game.c
void	quit(t_game *game);

//handle_keys.c
int	key_press(int keycode, t_game *g);


//start_game.c
void	start_game(char	*map_path);
void	set_game(t_game *game, char *map_path);

//start_map.c
void	set_map_tiles(t_game *game);
t_tile	new_tile(char type, int x, int y);
void	fill_map(t_game *game);
void	start_world(t_game *game);
void    set_map(t_game *game, char *map_path);

#endif
