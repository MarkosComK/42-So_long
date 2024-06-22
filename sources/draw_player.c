/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:50:48 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 14:53:54 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_player(t_game *game)
{
	ft_printf("its working!");
	mlx_put_image_to_window(game->mlx, game->win, game->map.img[1], S*game->player_x, S*game->player_y);
	return (0);
}
