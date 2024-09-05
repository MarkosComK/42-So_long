/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:08:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 10:16:16 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/so_long.h"

void	quit(t_game *game)
{
	int	i;

	free_map(game->map);
	i = 0;
	while (game->map.tiles[i])
		free(game->map.tiles[i++]);
	free(game->map.tiles);
	mlx_destroy_image(game->mlx, game->world->ptr);
	free(game->world);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->map.data);
	free(game->mlx);
	exit(0);
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (map.data[i])
		free(map.data[i++]);
}
