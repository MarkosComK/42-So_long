/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:42:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/25 14:10:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.str[y])
	{
		x = 0;
		while (game->map.str[y][x])
		{
			if (game->map.str[y][x] == 'P')
			{
				game->player.pos = (t_point){x, y};
			}
			x++;
		}
		y++;
	}
}