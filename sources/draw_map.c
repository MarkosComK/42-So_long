/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:15:21 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/22 15:28:04 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	s;

	s = 48;
	game->map.img = ft_calloc(sizeof(void **), 4);
	game->map.img[0] = mlx_xpm_file_to_image(game->mlx, GROUND_0, &s, &s);
	game->map.img[2] = mlx_xpm_file_to_image(game->mlx, WALL_0, &s, &s);
	game->map.img[1] = mlx_xpm_file_to_image(game->mlx, PLAYER_IDLE_0, &s, &s);
	game->map.img[3] = mlx_xpm_file_to_image(game->mlx, EXIT_0, &s, &s);
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
			if (game->map.map[i][j] == 'C')
			{
				game->player_x = j;
				game->player_y = i;
				game->map.map[i][j] = '0';
			}
			if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.img[3], S*j, S*i);
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.img[2], S*j, S*i);
			if (game->map.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->map.img[0], S*j, S*i);
			j++;
		}
		i++;
	}
}
