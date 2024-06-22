/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/22 17:31:10 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		count_lines(char *path)
{
	int		count;
	char	*str;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	init_map(t_game *game)
{
	game->map.map = NULL;
	game->map.img = NULL;
	game->map.columns = 0;
	game->map.lines = 0;
	game->map.width = 0;
	game->map.height = 0;
}

void	set_map(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	*str;

	init_map(game);
	fd = open(path, O_RDONLY);
	game->map.lines = count_lines(path);
	game->map.map = ft_calloc(sizeof(char **), game->map.lines + 1);
	i = 0;
	while ((str = get_next_line(fd))) 
	{
		game->map.map[i] = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
		ft_strlcpy(game->map.map[i], str, ft_strlen(str));
		free(str);
		i++;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
	close(fd);
}

void	game_start(char *path)
{
	t_game	game;
	set_map(path, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, S*game.map.columns, S*game.map.lines, "so_long");
	draw_map(&game);
	start_player(&game);
	game.player.pos_x = 0;
	game.player.pos_y = 0;
	restart_direction(&game);
	mlx_loop_hook(game.mlx, update_player, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
}

