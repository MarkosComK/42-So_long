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

void  load_walls(t_game *game, int s)
{
  game->map.img[2] = mlx_xpm_file_to_image(game->mlx, WALL_0, &s, &s);
  game->map.img[4] = mlx_xpm_file_to_image(game->mlx, WALL_R, &s, &s);
  game->map.img[5] = mlx_xpm_file_to_image(game->mlx, WALL_RC, &s, &s);
}

void	load_images(t_game *game)
{
	int	s;

	s = 48;
	game->map.img = ft_calloc(sizeof(void **), 6);
	game->map.img[0] = mlx_xpm_file_to_image(game->mlx, GROUND_0, &s, &s);
	game->map.img[1] = mlx_xpm_file_to_image(game->mlx, PLAYER_IDLE_0, &s, &s);
  game->map.img[3] = mlx_xpm_file_to_image(game->mlx, EXIT_0, &s, &s);
  load_walls(game, s);
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
      if (game->map.map[i][j] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->map.img[3], 48*j, 48*i);
      if (game->map.map[i][j] == '2')
        mlx_put_image_to_window(game->mlx, game->win, game->map.img[4], 48*j, 48*i);
      if (game->map.map[i][j] == '3')
        mlx_put_image_to_window(game->mlx, game->win, game->map.img[5], 48*j, 48*i);
      if (game->map.map[i][j] == '1')
			  mlx_put_image_to_window(game->mlx, game->win, game->map.img[2], 48*j, 48*i);
      if (game->map.map[i][j] == '0')
			  mlx_put_image_to_window(game->mlx, game->win, game->map.img[0], 48*j, 48*i);
			j++;
		}
		i++;
	}
}
