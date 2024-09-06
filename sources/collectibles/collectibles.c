/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:06:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 19:44:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_bottles(t_bottle *bottles)
{
	t_bottle	*current;

	current = bottles;
	ft_printf("STACK: \n");
	while (current)
	{
		ft_printf("node->pos{%i, %i}\n", current->pos.x, current->pos.y);
		current = current->next;
	}
}

void	init_collectibles(t_game *game)
{
	t_bottle	*node;
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	node = NULL;
	game->bottle = malloc(sizeof(t_bottle));
	game->bottle->sprite = NULL;
	game->bottle->pos = (t_pos){0, 0};
	game->bottle->next = NULL;
	while(game->map.data[i])
	{
		j = 0;
		while(game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'C')
			{
				bottle_push_tail(game->bottle, i, j);
			}
			j++;
		}
		i++;
	}
	print_bottles(game->bottle);
	free(node);
}
