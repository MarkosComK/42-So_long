/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:50:48 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/22 17:10:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map.img[1], 
			S*game->player.start_x, S*game->player.start_y);
	return (0);
}

int	update_player(t_game *game)
{
	clean_images(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->map.img[1], 
			2*game->player.pos_x, 2*game->player.pos_y);
	if (game->player.move.w)
		game->player.pos_y--;
	if (game->player.move.a)
		game->player.pos_x--;
	if (game->player.move.s)
		game->player.pos_y++;
	if (game->player.move.d)
		game->player.pos_x++;
	ft_printf("%i\n", game->player.start_x);
	ft_printf("%i\n", game->player.start_y);
	ft_printf("%i\n", game->player.pos_x);
	ft_printf("%i\n", game->player.pos_y);
	ft_printf("ENDS HERE\n");
	return (0);
}
