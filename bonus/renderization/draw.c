/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:04:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 10:06:15 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_map(t_game *game)
{
	int			y;
	int			x;
	t_img		*sprite;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			sprite = create_sprite(game, game->map.tiles[y][x].sprite_path);
			create_world(sprite, game, x, y);
			mlx_destroy_image(game->mlx, sprite->ptr);
			free(sprite);
		}
	}
}

void	draw_player(t_game *game)
{
	t_entity	player;
	char		*current_sprite;

	player = game->player;
	current_sprite = P_IDLE0;
	player.sprite = create_sprite(game, current_sprite);
	create_player(player.sprite, game, player.s_pos.x, player.s_pos.y);
	if (player.sprite)
		destroy_sprite(&player.sprite, game->mlx);
}

void	draw_bottles(t_game *game)
{
	t_bottle	*bottle;

	bottle = game->bottle;
	while (bottle)
	{
		bottle->sprite = create_sprite(game, COLLECTIBLE);
		create_player(bottle->sprite, game, bottle->pos.x, bottle->pos.y);
		mlx_destroy_image(game->mlx, bottle->sprite->ptr);
		free(bottle->sprite);
		bottle = bottle->next;
	}
}

void	draw_exit(t_game *game)
{
	t_exit	exit;

	exit = game->exit;
	exit.sprite[0] = create_sprite(game, EXIT_CLOSE);
	exit.sprite[1] = create_sprite(game, EXIT_OPEN);
	if (game->exit.open)
	{
		create_exit(exit.sprite[1], game, exit.pos.x, exit.pos.y);
	}
	else
	{
		create_exit(exit.sprite[0], game, exit.pos.x, exit.pos.y);
	}
	mlx_destroy_image(game->mlx, exit.sprite[1]->ptr);
	mlx_destroy_image(game->mlx, exit.sprite[0]->ptr);
	free(exit.sprite[1]);
	free(exit.sprite[0]);
}

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
				put_pixel(game->world, posx * SZ + x, posy * SZ + y - 38, color);
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