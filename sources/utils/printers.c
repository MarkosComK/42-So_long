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

void	print_player_struct(t_entity player)
{
	ft_printf("s_pos x: %i y: %i\n", player.s_pos.x, player.s_pos.y);
	ft_printf("d_pos x: %i y: %i\n", player.d_pos.x, player.d_pos.y);
	ft_printf("sprite: %s\n", player.sprite);
	ft_printf("current sprite: %i\n", player.current_sprite);
	ft_printf("player_sprite_idle: %s\n", player.sprite_idle);
}
