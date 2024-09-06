/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:32:10 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/06 14:36:54 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_exit_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.data[y])
	{
		x = 0;
		while (game->map.data[y][x])
		{
			if (game->map.data[y][x] == 'E')
			{
				game->exit.pos = (t_pos){x, y};
			}
			x++;
		}
		y++;
	}
}

void	init_exit(t_game *game)
{
	t_exit	exit;

	exit = game->exit;
	set_exit_pos(game);
	exit.sprite[0] = NULL;
	exit.sprite[1] = NULL;
	exit.open = FALSE;
}
