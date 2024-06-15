/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 21:10:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;
	void	*img;
	int		*w;
	int		*h;
	int		wi = 160;
	int		he = 230;

	w = &wi;
	h = &he;
	if (ac == 2)
	{
		game_start(av[1], &game);
		img	= mlx_xpm_file_to_image(game.mlx, "./assets/character/chort_run_anim_f1.xpm", w,  h);
		mlx_put_image_to_window(game.mlx, game.win, img, 50, 50);
		mlx_key_hook(game.win, game_over, &game);
		mlx_destroy_image(game.mlx, img);
		mlx_loop(game.mlx);
	}
}

