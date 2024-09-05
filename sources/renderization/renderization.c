/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:10 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 10:02:42 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_map(t_game *game);
void	render_map(t_game *game);
void	render_player(t_game *game);

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

void	draw_map(t_game *game)
{
	int			y;
	int			x;
	t_img		*sprite;
	char		*sprite_path;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			sprite_path = get_sprite_path(game, game->map.tiles[y][x].type, x, y);
			if (!sprite_path)
				return ;
			game->map.tiles[y][x].sprite_path = sprite_path;
			sprite = create_sprite(game, sprite_path);
			create_world(sprite, game, x, y);
			mlx_destroy_image(game->mlx, sprite->ptr);
			free(sprite);
		}
	}
}
