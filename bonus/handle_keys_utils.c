/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:09:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/08 12:01:33 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_sprites(t_game *game, t_entity *player, t_pos pos)
{
	wall_check(game, &game->player.s_pos, pos);
	player->d_pos = pos;
	player->current_sprite = 0;
	player->is_mov = 1;
}
