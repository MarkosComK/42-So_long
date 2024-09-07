/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:57:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 18:58:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	draw_player_r(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = player.right_sprites[player.current_sprite];
	player.sprite = create_sprite(game, current_sprite);
	create_player(player.sprite, game, player.s_pos.x, player.s_pos.y);
	if (player.sprite)
		destroy_sprite(&player.sprite, game->mlx);
}

void	draw_player_l(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = player.left_sprites[player.current_sprite];
	player.sprite = create_sprite(game, current_sprite);
	create_player(player.sprite, game, player.s_pos.x, player.s_pos.y);
	if (player.sprite)
		destroy_sprite(&player.sprite, game->mlx);
}
