/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:09:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 19:11:10 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	hole_check(t_game *game);

void	check_sprites(t_game *game, t_entity *player, t_pos pos)
{
	wall_check(game, &game->player.s_pos, pos);
	hole_check(game);
	player->d_pos = pos;
	player->current_sprite = 0;
	player->is_mov = 1;
}

void	hole_check(t_game *game)
{
	t_pos		new_pos;
	t_hole		*hole;
	int			index;

	new_pos = game->player.s_pos;
	hole = game->hole;
	index = 0;
	while (hole)
	{
		if (new_pos.x == hole->pos.x && new_pos.y == hole->pos.y)
		{
			game->player.death = 1;
			return ;
		}
		hole = hole-> next;
		index++;
	}
}

int	close_x(t_game *game)
{
	ft_printf(RED "Game interrupted by the user.\n" DEFAULT);
	quit(game);
	exit(0);
}

