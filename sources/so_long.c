/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 19:55:28 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	endgame(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (1);
}



int	main(void)
{
	t_game	game;
	void	*img;
	int		*w;
	int		*h;
	int		wi = 160;
	int		he = 230;

	w = &wi;
	h = &he;
	game_start(&game);
	img	= mlx_xpm_file_to_image(game.mlx, "./assets/character/chort_run_anim_f1.xpm", w,  h);
	mlx_put_image_to_window(game.mlx, game.win, img, 50, 50);
	mlx_key_hook(game.win, endgame, &game);
	//game_over(&game);
	mlx_destroy_image(game.mlx, img);
	mlx_loop(game.mlx);
}

