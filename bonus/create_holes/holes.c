/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:33 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 17:53:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_holes(t_game *game)
{
	t_enemy		*node;
	int			i;
	int			j;

	i = 0;
	j = 0;
	node = NULL;
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'H')
			{
				if (!game->hole)
					game->hole = hole_create(j, i);
				else
					hole_push_tail(game->hole, j, i);
			}
			j++;
		}
		i++;
	}
	print_holes(game);
}
