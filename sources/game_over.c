/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:46:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/16 18:46:41 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  game_over(t_game *game)
{
  int i;

  i = 0;
  while (game->map.map[i])
    free(game->map.map[i++]);
  mlx_destroy_window(game->mlx, game->win);
  mlx_destroy_display(game->mlx);
  free(game->map.map);
  free(game->mlx);
  exit(0);
}

void  clean_images(t_game *game)
{
  mlx_destroy_image(game->mlx, game->map.img[0]);
  mlx_destroy_image(game->mlx, game->map.img[1]);
  mlx_destroy_image(game->mlx, game->map.img[2]);
  mlx_destroy_image(game->mlx, game->map.img[3]);
  free(game->map.img);
}
