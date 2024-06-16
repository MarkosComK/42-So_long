/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:15:21 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 02:39:33 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	s;

	s = 48;
	game->map.img = malloc(sizeof(void *) * 2);
	game->map.img[0] = mlx_xpm_file_to_image(game->mlx, GROUND_0, &s, &s);
	game->map.img[1] = mlx_xpm_file_to_image(game->mlx, PLAYER_IDLE_0, &s, &s);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	load_images(game);
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map.img[0], 48*j, 48*i);
			j++;
		}
		i++;
	}
}
