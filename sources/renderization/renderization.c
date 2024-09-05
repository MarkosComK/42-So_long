/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:10 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 10:05:42 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_game(t_game *game)
{
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->world->ptr, -24, 0);
}
void	render_map(t_game *game)
{
	draw_map(game);
}

void	render_player(t_game *game)
{
	draw_player(game);
}