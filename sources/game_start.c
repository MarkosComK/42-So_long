/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 17:03:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game *game)
{
	t_map	map;
	int		fd;
	char	*str;
	char	**mp = NULL;

	fd = open("./maps/small.ber", O_RDONLY);
	ft_printf("%d", fd);
	str = get_next_line(fd);
	mp = malloc(sizeof(char **));
	mp[0] = malloc(sizeof(char *) * ft_strlen(str) + 1);
	mp[0] = str;
	map.map = NULL;
	map.map = mp;
	ft_printf("%s", map.map[0]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 480, 320, "so_long");
}
