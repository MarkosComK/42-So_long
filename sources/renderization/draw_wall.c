/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:52:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 11:56:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_wall_0(t_img *sprite, t_game *game, int posx, int posy)
{
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	trans_color;

	trans_color = 0xFFC0CB;
	y = -1;
	while (++y < sprite->h)
	{
		x = -1;
		while (++x < sprite->w)
		{
			color = get_color_in_pixel(sprite, x, y);
			if (color != trans_color)
			{
				put_pixel(game->world, posx * SZ + x, posy * SZ + y - 38,
			  color);
			}
		}
	}
}

void	draw_wall_0(t_game *game)
{
	int			y;
	int			x;
	t_img		*sprite;

	y = 1;
	while (y < game->map.rows - 1)
	{
		x = 1;
		while (x < game->map.cols - 1)
		{
			if (game->map.data[y][x] == '1')
			{
				sprite = create_sprite(game, WALL_INNER_0);
				create_wall_0(sprite, game, x, y);
				mlx_destroy_image(game->mlx, sprite->ptr);
				free(sprite);
			}
			x++;
		}
		y++;
	}
}

void	draw_wall_1(t_game *game)
{
	int			y;
	int			x;
	t_img		*sprite;

	y = 1;
	while (y < game->map.rows - 1)
	{
		x = 1;
		while (x < game->map.cols - 1)
		{
			if (game->map.data[y][x] == '1')
			{
				sprite = create_sprite(game, WALL_I_01);
				create_wall_0(sprite, game, x, y);
				mlx_destroy_image(game->mlx, sprite->ptr);
				free(sprite);
			}
			x++;
		}
		y++;
	}
}
