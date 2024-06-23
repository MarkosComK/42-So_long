/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:25:01 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 21:32:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

BOOL	valid_ber(char *path)
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
	columns = ft_strlen(map.str[i]);
	while (map.str[i])
	{
		if (ft_strlen(map.str[i]) != columns)
			return (0);
		i++;
	}
	map.cols = columns;
	return (1);
}

int	map_walls(t_map map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map.str[i])
	{
		j = 0;
		if (i == 0 || i == map.rows)
		{
			while (map.str[i][j])
			{
				if (map.str[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (map.str[i][0] != '1' ||
				map.str[i][map.cols - 1] != '1')
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
	while (map.str[++i])
	{
		j = -1;
		while (map.str[i][++j])
		{
			if (map.str[i][j] == 'C')
				map.collectables++;
			else if (map.str[i][j] == 'P')
				map.player++;
			else if (map.str[i][j] == 'E')
				map.exits++;
		}
	}
	if (map.collectables >= 1 && map.exits == 1 && map.player == 1)
		return (1);
	return (0);
}

void	valid_map(t_game *game)
{
	if (!game->map.str[0])
		error_msg("Map is empty!");
	if (!map_retangular(game->map))
		error_msg("Map is not retangular!");
    if (!map_components(game->map))
        error_msg("Map doesn't have the correct components!");
	if (!map_walls(game->map))
		exit_message(game, "Map isn't completely surrounded by walls!\n");
	game->map.width = game->map.cols * SIZE;
	game->map.height = game->map.rows * SIZE;
}