/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/14 20:35:14 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	endgame(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
	}
	return (1);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 320, 480, "Hello world!");
	mlx_key_hook(game.win, endgame, &game);
	mlx_loop(game.mlx);
}

