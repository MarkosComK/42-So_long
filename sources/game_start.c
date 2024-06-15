/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 17:23:57 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game *game)
{
	t_map	map;
	int		fd;

	fd = open("./maps/small.ber", O_RDONLY);
	ft_printf("%d", fd);
	map.map = malloc(sizeof(char **));
	map.map[0] = get_next_line(fd);
	ft_printf("%s", map.map[0]);
	free(map.map[0]);
	free(map.map);
	close(fd);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 480, 320, "so_long");
}
