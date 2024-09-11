/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:13:32 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 19:14:12 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	draw_death(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = P_DEATH;
	player.sprite = create_sprite(game, current_sprite);
	create_player(player.sprite, game, player.s_pos.x, player.s_pos.y);
	if (player.sprite)
		destroy_sprite(&player.sprite, game->mlx);
}
