/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:42:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 22:07:03 by marsoare         ###   ########.fr       */
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
				game->player = (t_entity){x, y};
			}
			x++;
		}
		y++;
	}
}