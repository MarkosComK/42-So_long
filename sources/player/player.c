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
	t_pos		s_pos;
	t_pos		d_pos;
	t_entity	player;

	player = game->player;
	set_player_pos(game);
	player.d_pos = (t_pos){0, 0};
	player.sprite = NULL;
	player.current_sprite = 0;
	load_player_sprite(game);
}

void	load_player_sprite(t_game *game)
{
	t_entity	player;

	player = game->player;
	player.sprite_idle[0] = P_IDLE0;
}

void	create_player(t_img *sprite, t_game *game, int posx, int posy)
{
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	trans_color;

	trans_color = 0xFFC0CB;
	y = -1;
	while (++y < sprite->h)
	{
		x = -1;
		while (++x < sprite->w)
		{
			color = get_color_in_pixel(sprite, x, y);
			if (color != trans_color)
			{
				put_pixel(game->world, posx * SZ + x, posy * SZ + y, color);
			}
		}
	}
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
