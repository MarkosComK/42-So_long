/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_holes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:16:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 17:59:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	create_holes(t_img *sprite, t_game *game, int posx, int posy)
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
				put_pixel(game->world, posx * SZ + x, posy * SZ + y, color);
			}
		}
	}
}

void	draw_hole(t_game *game)
{
	t_hole	*hole;
	t_pos	p_pos;

	hole = game->hole;
	p_pos = game->player.s_pos;
	while (hole)
	{
		hole->sprite[0] = create_sprite(game, HOLE_CLOSE);
		hole->sprite[1] = create_sprite(game, HOLE_OPEN);
		if (hole->pos.x == p_pos.x && hole->pos.y == p_pos.y)
		{
			create_holes(hole->sprite[1], game, hole->pos.x, hole->pos.y);
		}
		else
		{
			create_holes(hole->sprite[0], game, hole->pos.x, hole->pos.y);
		}
		mlx_destroy_image(game->mlx, hole->sprite[0]->ptr);
		mlx_destroy_image(game->mlx, hole->sprite[1]->ptr);
		free(hole->sprite[0]);
		free(hole->sprite[1]);
		hole = hole->next;
	}
}
