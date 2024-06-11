/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/11 15:01:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct	s_game {
	void	*connection;
	void	*window;
}				t_game;

int	main(void)
{
	t_game	game;

	game.connection = mlx_init();
	game.window = mlx_new_window(game.connection, 640, 480, "Hello world!");
	if (!game.window)
	{
		mlx_destroy_display(game.connection);
		free(game.connection);
		free(game.window);
		return (1);
	}
	mlx_loop(game.connection);
	mlx_destroy_display(game.connection);
	mlx_destroy_window(game.connection, game.window);
	free(game.connection);
	free(game.window);
	return(0);
}


