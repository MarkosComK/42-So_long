/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:10 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 19:29:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_game(t_game *game)
{
	render_map(game);
	render_walls_0(game);
	render_exit(game);
	render_holes(game);
	render_player(game);
	render_collectibles(game);
	render_walls_1(game);
	mlx_put_image_to_window(game->mlx, game->win, game->world->ptr, -24, 0);
	mlx_string_put(game->mlx, game->win, 10, 16, 0xFFF000, "moves");
	mlx_string_put(game->mlx, game->win, 19, 27, 0xFFF000,
		ft_itoa(game->player.moves));
}

void	render_map(t_game *game)
{
	draw_map(game);
}

void	render_player(t_game *game)
{
	if (game->player.death)
		draw_death(game);
	else if (game->player.d_pos.x == 1)
		draw_player_r(game);
	else if (game->player.d_pos.x == -1)
		draw_player_l(game);
	else if (game->player.d_pos.y == 1)
		draw_player_b(game);
	else if (game->player.d_pos.y == -1)
		draw_player_t(game);
	else
		draw_player(game);
}

void	render_collectibles(t_game *game)
{
	draw_bottles(game);
}

void	render_exit(t_game *game)
{
	draw_exit(game);
}
