/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/13 09:06:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "./colors.h"
# include "../libraries/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <time.h>

# define SZ 32
//walls
# define WALL "./sprites/wall-0.xpm"
# define WALL_L "./sprites/wall-l.xpm"
# define WALL_R "./sprites/wall-r.xpm"
# define WALL_LT "./sprites/wall-lt.xpm"
# define WALL_RT "./sprites/wall-rt.xpm"
# define WALL_LB "./sprites/wall-lb.xpm"
# define WALL_RB "./sprites/wall-rb.xpm"
# define WALL_INNER_0 "./sprites/wall-inner-0.xpm"
# define WALL_I_01 "./sprites/wall-inner-01.xpm"
# define WALL_INNER_2 "./sprites/wall-inner-2.xpm"
//floors
# define FLOOR0 "./sprites/floor-0.xpm"
# define FLOOR1 "./sprites/floor-1.xpm"
# define FLOOR2 "./sprites/floor-2.xpm"
# define FLOOR3 "./sprites/floor-3.xpm"
# define FLOOR4 "./sprites/floor-4.xpm"
//player
# define P_IDLE0 "./sprites/idle-01.xpm"
# define P_DEATH "./sprites/death.xpm"
# define P_R_RUN_0 "./sprites/r-run-0.xpm"
# define P_R_RUN_1 "./sprites/r-run-1.xpm"
# define P_R_RUN_2 "./sprites/r-run-2.xpm"
# define P_R_RUN_3 "./sprites/r-run-3.xpm"
# define P_L_RUN_0 "./sprites/l-run-0.xpm"
# define P_L_RUN_1 "./sprites/l-run-1.xpm"
# define P_L_RUN_2 "./sprites/l-run-2.xpm"
# define P_L_RUN_3 "./sprites/l-run-3.xpm"
//collectible
# define ENEMY_0 "./sprites/enemy-0.xpm"
# define ENEMY_1 "./sprites/enemy-1.xpm"
# define ENEMY_2 "./sprites/enemy-2.xpm"
# define ENEMY_3 "./sprites/enemy-3.xpm"
//exit
# define EXIT_CLOSE "./sprites/floor-1.xpm"
# define EXIT_OPEN "./sprites/door-open.xpm"
//holes
# define HOLE_CLOSE "./sprites/hole-close.xpm"
# define HOLE "./sprites/collectible-0.xpm"
# define HOLE_OPEN "./sprites/hole-open.xpm"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_sprite
{
	t_img	wall;
}				t_sprite;

typedef struct s_pos
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

typedef struct s_map
{
	char		**data;
	int			rows;
	int			cols;
	int			width;
	int			height;
	int			collectables;
	int			player;
	int			exits;
	t_tile		**tiles;
}				t_map;

typedef struct s_entity
{
	t_pos		s_pos;
	t_pos		d_pos;
	t_img		*sprite;
	int			delay;
	int			is_mov;
	int			death;
	int			current_sprite;
	char		*sprite_idle[2];
	char		*right_sprites[4];
	char		*left_sprites[4];
	int			points;
	int			moves;
}				t_entity;

typedef struct s_exit
{
	t_pos		pos;
	t_img		*sprite[2];
	bool		open;
}				t_exit;

typedef struct s_enemy
{
	t_pos			pos;
	t_img			*sprite;
	int				current_s;
	char			*sprite_idle[4];
	struct s_enemy	*next;
}				t_enemy;

typedef struct s_hole
{
	t_pos			pos;
	t_img			*sprite;
	struct s_hole	*next;
}				t_hole;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_entity		player;
	t_img			*world;
	t_enemy			*enemy;
	t_hole			*hole;
	t_exit			exit;
	unsigned int	path;
	unsigned int	path_coll;
	int				e_delay;
}					t_game;

/*
 * checkers/
 */
//validate_ber.c
bool			validate_ber(char *path);
//validate_map.c
void			validate_map(t_game *game);
int				map_retangular(t_map map);
int				map_components(t_map map);
int				map_walls(t_map map);
int				map_path(t_game *game);
//validate_utils.c
void			floodfill(t_game *game, char **matrix, t_pos cur);
void			map_matrix_delete(char **map_bytes);

/*
 * collectibes/
 */
//collectibles.c
void			init_collectibles(t_game *game);
//list_utils.c
t_enemy			*ft_bottlelast(t_enemy *lst);
t_enemy			*bottle_add(t_enemy *node, int x, int y);
t_enemy			*bottle_push_tail(t_enemy *stack, int x, int y);
t_enemy			*bottle_create(int x, int y);
int				bottles_size(t_enemy *lst);
/*
 * create_holes.c
 */
//draw_holes.c
void			create_holes(t_img *sprite, t_game *game, int posx, int posy);
void			draw_hole(t_game *game);
//holes.c
void			init_holes(t_game *game);
//list_utils_holes.c
t_hole			*ft_holelast(t_hole *lst);
t_hole			*hole_add(t_hole *node, int x, int y);
t_hole			*hole_push_tail(t_hole *stack, int x, int y);
t_hole			*hole_create(int x, int y);
int				hole_size(t_hole *lst);
//render_holes.c
void			render_holes(t_game *game);
/*
 * exit/
 */
//exit.c
void			init_exit(t_game *game);
void			create_exit(t_img *sprite, t_game *game, int posx, int posy);

/*
 * game_over/
 */
//frees.c
void			destroy_sprite(t_img **sprite, void *mlx);
void			free_map(t_map map);
void			free_tiles(t_map map);
void			free_bottles(t_enemy *bottles);
void			free_holes(t_hole *holes);

/*
 * player/
 */
//player.c
void			init_player(t_game *game);
void			load_player_sprite(t_game *game);
void			set_player_pos(t_game *game);
void			create_player(t_img *sprite, t_game *game, int posx, int posy);

//quit.c
void			quit(t_game *game);

/*
 * renderization/
 */
//draw.c
void			draw_player(t_game *game);
void			draw_map(t_game *game);
void			draw_collectibles(t_game *game);
void			draw_bottles(t_game *game);
void			draw_exit(t_game *game);
//draw_animate_player.c
void			draw_player_r(t_game *game);
void			draw_player_l(t_game *game);
//draw_animate_player2.c
void			draw_player_b(t_game *game);
void			draw_player_t(t_game *game);
//draw_death.c
void			draw_death(t_game *game);
//draw_wall.c
void			draw_wall_0(t_game *game);
void			draw_wall_1(t_game *game);
//render_wall.c
void			render_walls_0(t_game *game);
void			render_walls_1(t_game *game);
//renderization.c
void			render_game(t_game *game);
void			render_map(t_game *game);
void			render_player(t_game *game);
void			render_collectibles(t_game *game);
void			render_exit(t_game *game);

/*
 * sprites/
 */
//create_sprites.c
t_img			*create_sprite(t_game *game, char *sprite_path);
void			create_map(t_game *game);
char			*get_sprite_path(t_game *game, char c, int x, int y);
void			create_world(t_img *sprite, t_game *game, int posx, int posy);

//handle_pixel.c
void			put_pixel(t_img *sprite, int x, int y, int color);
unsigned int	get_color_in_pixel(t_img *sprite, int x, int y);

/*
 * utils/
 */
//printers.c
int				error_msg(char *msg);
int				error_map(char *msg, t_game *game);
void			print_map(t_game *game);
void			print_player(t_game *game);
void			print_bottles(t_game *game);
void			print_holes(t_game *game);
//randomizer.c
char			*randomize_floor(int x, int y, t_map map);
t_pos			randomize_pos(t_pos pos, char **map, t_pos p_pos, t_game *game);
//utils.c
int				count_lines(char *map_path);
int				print_fps(clock_t current_time);

//end_game.c
void			quit(t_game *game);

//handle_keys.c
int				key_press(int keycode, t_game *g);
void			bottle_check(t_game *game, t_pos *pos);
void			exit_check(t_game *game, t_pos *pos);
void			wall_check(t_game *game, t_pos *pos, t_pos xy);
//handle_keys_utils.c
void			check_sprites(t_game *game, t_entity *player, t_pos pos);
int				close_x(t_game *game);

//start_game.c
void			start_game(char	*map_path);
void			set_game(t_game *game, char *map_path);

//start_map.c
void			set_map_tiles(t_game *game);
t_tile			new_tile(char type, int x, int y);
void			fill_map(t_game *game);
void			start_world(t_game *game);
void			set_map(t_game *game, char *map_path);

#endif
