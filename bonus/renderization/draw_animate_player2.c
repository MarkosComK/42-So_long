/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:57:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 22:07:15 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	create_player_t(t_img *sprite, t_game *game, int posx, int posy);
void	create_player_b(t_img *sprite, t_game *game, int posx, int posy);

void	draw_player_b(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = player.right_sprites[player.current_sprite];
	if (player.delay == 4 && game->player.current_sprite != 3)
	{
		player.sprite = create_sprite(game, current_sprite);
		create_player_b(player.sprite, game, player.s_pos.x, player.s_pos.y);
		game->player.current_sprite = (game->player.current_sprite + 1) % 4;
		if (player.sprite)
			destroy_sprite(&player.sprite, game->mlx);
	}
	else
	{
		player.sprite = create_sprite(game, current_sprite);
		create_player_b(player.sprite, game, player.s_pos.x, player.s_pos.y);
		if (player.sprite)
			destroy_sprite(&player.sprite, game->mlx);
	}
}

void	draw_player_t(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = player.left_sprites[player.current_sprite];
	if (player.delay == 4 && game->player.current_sprite != 3)
	{
		player.sprite = create_sprite(game, current_sprite);
		create_player_t(player.sprite, game, player.s_pos.x, player.s_pos.y);
		game->player.current_sprite = (game->player.current_sprite + 1) % 4;
		if (player.sprite)
			destroy_sprite(&player.sprite, game->mlx);
	}
	else
	{
		player.sprite = create_sprite(game, current_sprite);
		create_player_t(player.sprite, game, player.s_pos.x, player.s_pos.y);
		if (player.sprite)
			destroy_sprite(&player.sprite, game->mlx);
	}
}

void	create_player_t(t_img *sprite, t_game *game, int posx, int posy)
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
				put_pixel(game->world, posx * SZ + x + 2, posy * SZ
					- (game->player.current_sprite * 6) + 2 + y, color);
			}
		}
	}
}

void	create_player_b(t_img *sprite, t_game *game, int posx, int posy)
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
				put_pixel(game->world, posx * SZ + 4 + x, posy * SZ
					+ (game->player.current_sprite * 6) - 32 + y, color);
			}
		}
	}
}
