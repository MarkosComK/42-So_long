/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:25:01 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 13:32:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

BOOL	validate_ber(char *path)
{
	size_t		len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".ber", 4))
		return (true);
	return (false);
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
		}
	}
	if (map.collectables >= 1 && map.exits == 1 && map.player == 1)
		return (1);
	return (0);
}

void	validate_map(t_game *game)
{
	if (!game->map.data[0])
		error_msg("Map is empty!");
	if (!map_retangular(game->map))
		error_msg("Map is not retangular!");
	if (!map_components(game->map))
		error_msg("Map doesn't have the correct components!");
	if (!map_walls(game->map))
		error_msg("Map isn't completely surrounded by walls!");
	game->map.cols = ft_strlen(game->map.data[0]);
	game->map.width = game->map.cols * SZ;
	game->map.height = game->map.rows * SZ;
}
