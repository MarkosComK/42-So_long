/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:06:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/13 09:07:32 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_collectibles(t_game *game)
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
				if (!game->enemy)
					game->enemy = bottle_create(j, i);
				else
					bottle_push_tail(game->enemy, j, i);
			}
			j++;
		}
		i++;
	}
}
