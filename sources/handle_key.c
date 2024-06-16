/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:53 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 14:54:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		handle_key(int keycode, t_game *game)
{
	if (keycode == XK_r)
	{
		ft_printf("working");
		draw_map(game);
		draw_player(game);
	}
  if (keycode == XK_d)
  {
    game->player_x++;
    draw_map(game);
    draw_player(game);
  }
	if (keycode == XK_Escape)
	{
    game_over(game);
	}
	return (1);
}
