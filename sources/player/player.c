
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:42:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 14:24:24 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_player(t_game *game)
{
	t_pos	s_pos;
	t_pos	d_pos;
	t_entity	player;

	player = game->player;
	set_player_pos(game);
	s_pos = (t_pos){player.s_pos.x, player.s_pos.x}; //del later
	player.d_pos = (t_pos){0, 0};
	player.current_sprite = 0; //load sprite here
	d_pos = player.d_pos; //del later
	
	
	ft_printf("dest_pos x: %i y: %i\n", d_pos.x, d_pos.y);
}

void	load_player_sprite(t_game *game)
{
	(void) game;

}

void	set_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.data[y])
	{
		x = 0;
		while (game->map.data[y][x])
		{
			if (game->map.data[y][x] == 'P')
			{
				game->player.s_pos = (t_pos){x, y};
			}
			x++;
		}
		y++;
	}
}
