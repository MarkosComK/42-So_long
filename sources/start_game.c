/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 12:51:12 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_game(t_game *game, char	*map_path)
{
	ft_bzero(game, sizeof(t_game));
	set_map(game, map_path);
	validate_map(game);
	set_player_pos(game);
}

void	start_game(char	*map_path)
{
	t_game	game;
	
	set_game(&game, map_path);
	game.mlx = mlx_init();
	game.win= mlx_new_window(game.mlx, game.map.width, game.map.height + SIZE, "So Long");
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
}

