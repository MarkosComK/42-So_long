/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 22:29:23 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win= mlx_new_window(game->mlx, game->map.width, game->map.height + SIZE, "So Long");
	mlx_loop(game->mlx);
}

void	set_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	set_map(&game, map_name);
	validate_map(&game);
	set_player_pos(&game);
	start_game(&game);
}