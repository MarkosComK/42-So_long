/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:42:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 21:51:24 by marsoare         ###   ########.fr       */
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
	ft_printf("[%i] x: \n", game->player.pos.x);
	ft_printf("[%i] y: \n", game->player.pos.y);
}