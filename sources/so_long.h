/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:52:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 22:01:13 by marsoare         ###   ########.fr       */
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
	int		width;
	int		height;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		*w;
	int		*h;
	int		wi;
	int		he;
}				t_img;

void	game_start(char *path, t_game *game);
int		game_over(int keycode, t_game *game);

#endif
