
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
	player.sprite = NULL;
	player.current_sprite = 0; //save current sprite here
	load_player_sprite(game);
	d_pos = player.d_pos; //del later
	
	
	ft_printf("dest_pos x: %i y: %i\n", d_pos.x, d_pos.y);
}

void	load_player_sprite(t_game *game)
{
	t_entity	player;

	player = game->player;
	player.sprite_idle[0] = P_IDLE0;
}

void	draw_player(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = P_IDLE0;
	player.sprite = create_sprite(game, current_sprite);
	create_player(player.sprite, game, player.s_pos.x, player.s_pos.y);
	if (player.sprite)
		destroy_sprite(&player.sprite, game->mlx);
}

void	destroy_sprite(t_img **sprite, void *mlx)
{
	if (*sprite)
	{
		if ((*sprite)->ptr)
		{
			mlx_destroy_image(mlx, (*sprite)->ptr);
			(*sprite)->ptr = NULL;
		}
		free(*sprite);
		*sprite = NULL;
	}
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
