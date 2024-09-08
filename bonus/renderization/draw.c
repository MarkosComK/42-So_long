/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:04:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/08 12:50:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	t_enemy	*enemy;

	enemy = game->enemy;
	while (enemy)
	{
		enemy->sprite = create_sprite(game, ENEMY_0);
		create_player(enemy->sprite, game, enemy->pos.x, enemy->pos.y);
		mlx_destroy_image(game->mlx, enemy->sprite->ptr);
		free(enemy->sprite);
		enemy = enemy->next;
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
