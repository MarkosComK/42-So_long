/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 14:43:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;
	if (ac == 2)
	{
		game_start(av[1], &game);
		//draw_map(&game);
		mlx_key_hook(game.win, handle_key, &game);
		mlx_loop(game.mlx);
	}
}

