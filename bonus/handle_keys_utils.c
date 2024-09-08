/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:09:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/08 10:17:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_sprites(t_entity *player, t_pos pos)
{
	player->d_pos = pos;
	player->current_sprite = 0;
	player->is_mov = 1;
}
