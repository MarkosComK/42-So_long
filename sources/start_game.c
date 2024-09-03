/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 21:05:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(char	*map_path)
{
	t_game	game;
	
	set_game(&game, map_path);
	fill_map(&game);
	game.mlx = mlx_init();
	game.win= mlx_new_window(game.mlx, game.map.width, game.map.height + SZ, "So Long");
	start_world(&game);
	create_map(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.world->ptr, 0, 0);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
}

void	set_game(t_game *game, char *map_path)
{
	ft_bzero(game, sizeof(t_game));
	set_map(game, map_path);
	validate_map(game);
	set_player_pos(game);
}
