/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:33:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 11:07:57 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_map_tiles(t_game *game)
{
	int	i;

	i = 0;
	game->map.tiles = (t_tile **)ft_calloc(game->map.rows + 1, sizeof(t_tile *)
			* SZ);
	if (!game->map.tiles)
	{
		ft_putendl_fd("Tiles alocation failes", 2);
		exit (1);
	}
	while (i < game->map.rows)
	{
		game->map.tiles[i] = (t_tile *)ft_calloc(sizeof(t_tile *) * SZ,
				ft_strlen(game->map.data[i]) + 1);
		if (!game->map.tiles[i++])
		{
			ft_putendl_fd("Tiles alocation failes", 2);
			exit (1);
		}
		i++;
	}
}

t_tile	new_tile(char type, int x, int y)
{
	t_tile	tile;

	tile.type = type;
	tile.pos.x = x;
	tile.pos.y = y;
	return (tile);
}

void	fill_map(t_game *game)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**mapd;

	mapd = game->map.data;
	y = 0;
	i = 0;
	j = 0;
	while (mapd[i])
	{
		x = 0;
		j = 0;
		while (mapd[i][j])
		{
			game->map.tiles[y][x] = new_tile(mapd[i][j], x * SZ, y * SZ);
			game->map.tiles[y][x].sprite_path = NULL;
			x++;
			j++;
		}
		i++;
		y++;
	}
}

void	start_world(t_game *game)
{
	t_img	*world;

	world = (t_img *)ft_calloc(1, sizeof(t_img));
	world->ptr = mlx_new_image(game->mlx, game->map.cols * SZ,
			game->map.rows * SZ);
	if (!world->ptr)
	{
		ft_putendl_fd("Failed to alloc world", 2);
		exit (1);
	}
	world->addr = mlx_get_data_addr(world->ptr, &world->bpp,
			&world->line_len, &world->endian);
	world->w = game->map.cols * SZ;
	world->h = game->map.rows * SZ;
	game->world = world;
}

void	set_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(map_path, O_RDONLY);
	game->map.rows = count_lines(map_path);
	game->map.data = ft_calloc(sizeof(char **), game->map.rows + 1);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		game->map.data[i] = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
		ft_strlcpy(game->map.data[i], str, ft_strlen(str));
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	set_map_tiles(game);
}
