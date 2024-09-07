/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:06:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 11:59:05 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_collectibles(t_game *game)
{
	t_bottle	*node;
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
			if (game->map.data[i][j] == 'C')
			{
				if (!game->bottle)
					game->bottle = bottle_create(j, j);
				else
					bottle_push_tail(game->bottle, j, i);
			}
			j++;
		}
		i++;
	}
	game->map.collectables = bottles_size(game->bottle);
}
