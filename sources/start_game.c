/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 22:09:39 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_message(game, "Error in mlx_init().\n");
	game->window = mlx_new_window(game->mlx, game->map->width,
			game->map->height + SIZE, "So Long");
	if (!game->window)
		exit_message(game, "Error in mlx_window().\n");
	init_player(game);
	init_melons(game);
	init_enemies(game);
	load_images(game);
	load_image_wall(game);
	put_graphics(game);
	mlx_hook(game->window, 2, KEY_MASK, &key_press, game);
	mlx_hook(game->window, 17, CLOSE_MASK, &quit, game);
	mlx_loop_hook(game->mlx, &put_game, game);
	mlx_loop(game->mlx);
}

void	set_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	set_map(&game, map_name);
	validate_map(&game);
	set_player_pos(&game);
}