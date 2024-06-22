/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:53 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/22 17:02:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart_direction(t_game *game)
{
	game->player.move.w = 0;
	game->player.move.a = 0;
	game->player.move.s = 0;
	game->player.move.d = 0;
}

int handle_key(int keycode, t_game *game)
{
	restart_direction(game);
	if (keycode == XK_r)
	{
		game->start = 1;
	}
	if (keycode == XK_w)
	{
		game->player.pos_y--;
		game->player.move.w = 1;
	}
	if (keycode == XK_a)
	{
		game->player.pos_x--;
		game->player.move.a = 1;
	}
	if (keycode == XK_s)
	{
		game->player.pos_y++;
		game->player.move.s = 1;
	}
	if (keycode == XK_d)
	{
		game->player.pos_x++;
		game->player.move.d = 1;
	}
	if (keycode == XK_Escape)
		game_over(game);
	return (1);
}
