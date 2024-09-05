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
	int i = 5;
	while (i > 0)
	{
		ft_printf("pos{%i, %i}\n", current->pos.x, current->pos.y);
		current = current->next;
		i--;
	}
}

void	init_collectibles(t_game *game)
{
	t_bottle	*node;
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	node = ft_calloc(sizeof(t_bottle), 1);
	while(game->map.data[i])
	{
		j = 0;
		while(game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'C')
			{
				node->sprite = NULL;
				node->pos = (t_pos){i, j};
				node->next = NULL;
				ft_bottleadd_back(&game->bottle, node);
				ft_printf("%c", game->map.data[i][j]);
			}
			j++;
		}
		ft_printf("\n");
		i++;
	}
	print_bottles(game->bottle);
	free(node);
}
