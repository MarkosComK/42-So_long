/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/26 14:15:20 by marsoare         ###   ########.fr       */
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

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

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
void	quit(t_game *game);
int		key_press(int keycode, t_game *g);
t_img   new_file_img(char *path, t_game *game);
//MAP CHECKERS
void	validate_map(t_game *game);
// UTILITIES TO DELETE LATER
void	print_map(t_game *game);
int     error_msg(char *msg);

#endif