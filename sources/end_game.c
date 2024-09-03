/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:07:17 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 13:38:24 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.data[i])
		free(game->map.data[i++]);
	i = 0;
	while (game->map.tiles[i])
		free(game->map.tiles[i++]);
	free(game->map.tiles);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->map.data);
	free(game->mlx);
	exit(0);
}
