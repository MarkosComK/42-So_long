/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:27:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 21:38:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./colors.h"
# include "../libraries/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>

# define BOOL int
# define true 1
# define false 0

# define SIZE 32;

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
    t_map   map;
}               t_game;

BOOL	validate_ber(char *path);
void	start_game(char *map_name);
void    set_map(t_game *game, char *map_path);
//MAP CHECKERS
void	validate_map(t_game *game);
// UTILITIES TO DELETE LATER
void	print_map(t_game *game);
int     error_msg(char *msg);

#endif