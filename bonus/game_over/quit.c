/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:08:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 17:00:00 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	quit(t_game *game)
{
	free_map(game->map);
	free_tiles(game->map);
	free_bottles(game->enemy);
	free_holes(game->hole);
	mlx_destroy_image(game->mlx, game->world->ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->world);
	free(game->mlx);
	exit(0);
}
