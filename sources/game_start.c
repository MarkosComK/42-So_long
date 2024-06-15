/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 21:09:49 by marsoare         ###   ########.fr       */
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

int		count_lines(char *path)
{
	int		count;
	char	*str;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	set_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*str;

	init_map(map);
	fd = open(path, O_RDONLY);
	map->map = malloc(sizeof(char **) * count_lines(path));
	i = 0;
	while ((str = get_next_line(fd))) 
	{
		map->map[i] = malloc(sizeof(char *) * ft_strlen(str));
		map->map[i] = ft_strdup(str);
		free(str);
		ft_printf("%s", map->map[i]);
		i++;
	}
	close(fd);
}

void	game_start(char *path, t_game *game)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	set_map(path, map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 480, 320, "so_long");
}

