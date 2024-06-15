/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 17:47:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->img = NULL;
	map->columns = 0;
	map->lines = 0;
}

void	set_map(t_map *map)
{
	int		fd;

	init_map(map);
	fd = open("./maps/small.ber", O_RDONLY);
	map->map = malloc(sizeof(char **));
	map->map[0] = get_next_line(fd);
}

void	game_start(t_game *game)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	set_map(map);

	ft_printf("%s", map->map[0]);
	free(map->map[0]);
	free(map->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 480, 320, "so_long");
}

