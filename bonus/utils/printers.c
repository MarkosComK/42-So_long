/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:46:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 19:47:30 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	error_msg(char *msg)
{
	ft_printf("ERROR\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.data[i])
	{
		ft_printf("%s\n", game->map.data[i]);
		i++;
	}
}

void	print_player(t_game *game)
{
	t_entity	player;

	player = game->player;
	ft_printf("Player:\n");
	ft_printf("s_pos x: %i y: %i\n", player.s_pos.x, player.s_pos.y);
	ft_printf("d_pos x: %i y: %i\n", player.d_pos.x, player.d_pos.y);
	ft_printf("\n");
}

void	print_bottles(t_game *game)
{
	t_bottle	*current;

	current = game->bottle;
	ft_printf("BOTTLES: \n");
	while (current)
	{
		ft_printf("node->pos{%i, %i}\n", current->pos.x, current->pos.y);
		current = current->next;
	}
	ft_printf("\n");
}