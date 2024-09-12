/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/12 16:33:27 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_loop_hook(t_game *game)
{
	if (game->player.points == game->map.collectables)
		game->exit.open = true;
	bottle_check(game, &game->player.s_pos);
	exit_check(game, &game->player.s_pos);
	render_game(game);
	return (0);
}

void	start_game(char	*map_path)
{
	t_game	game;

	set_game(&game, map_path);
	fill_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width - 48,
			game.map.height, "So Long");
	start_world(&game);
	create_map(&game);
	mlx_hook(game.win, 02, 1L << 0, key_press, &game);
	mlx_loop_hook(game.mlx, game_loop_hook, &game);
	mlx_loop(game.mlx);
}

int	count_collect(t_game *game)
{
	int			i;
	int			j;
	int			collect;

	i = 0;
	j = 0;
	collect = 0;
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'C')
			{
				collect += 1;
			}
			j++;
		}
		i++;
	}
	return (collect);
}

void	set_game(t_game *game, char *map_path)
{
	ft_bzero(game, sizeof(t_game));
	set_map(game, map_path);
	game->map.collectables = count_collect(game);
	set_player_pos(game);
	validate_map(game);
	init_player(game);
	init_collectibles(game);
	init_exit(game);
}
