/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:54:14 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/13 09:06:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	validate_map(t_game *game)
{
	if (!game->map.data[0])
		error_map("Map is invalid", game);
	if (!map_retangular(game->map))
		error_map("Map is invalid", game);
	if (!map_components(game->map))
		error_map("Map is invalid", game);
	if (!map_walls(game->map))
		error_map("Map is invalid", game);
	else if (!map_path(game))
		error_map("Map is invalid", game);
	game->map.cols = ft_strlen(game->map.data[0]);
	game->map.width = game->map.cols * SZ;
	game->map.height = game->map.rows * SZ;
}

int	map_retangular(t_map map)
{
	size_t	columns;
	int		i;

	i = 0;
	columns = ft_strlen(map.data[i]);
	while (map.data[i])
	{
		if (ft_strlen(map.data[i]) != columns)
			return (0);
		i++;
	}
	map.cols = columns;
	return (1);
}

int	map_components(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (map.data[++i])
	{
		j = -1;
		while (map.data[i][++j])
		{
			if (map.data[i][j] == 'C')
				map.collectables++;
			else if (map.data[i][j] == 'P')
				map.player++;
			else if (map.data[i][j] == 'E')
				map.exits++;
			else if (map.data[i][j] == 'H')
					continue ;
			else if (map.data[i][j] != '0' && map.data[i][j] != '1')
				return (0);
		}
	}
	if (map.collectables >= 1 && map.exits == 1 && map.player == 1)
		return (1);
	return (0);
}

int	map_walls(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.data[i])
	{
		j = 0;
		if (i == 0 || i == map.rows)
		{
			while (map.data[i][j])
			{
				if (map.data[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (map.data[i][0] != '1' ||
				map.data[i][map.cols] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	map_path(t_game *game)
{
	char	**matrix_map;
	int		i;

	i = 0;
	matrix_map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!matrix_map)
		error_msg("Mamory allocation fail!\n");
	while (game->map.data[i])
	{
		matrix_map[i] = ft_strdup(game->map.data[i]);
		i++;
	}
	matrix_map[i] = NULL;
	floodfill(game, matrix_map, game->player.s_pos);
	map_matrix_delete(matrix_map);
	return (game->path == 1 && (int)game->path_coll == game->map.collectables);
}
