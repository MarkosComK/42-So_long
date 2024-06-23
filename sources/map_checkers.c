/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:25:01 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 20:35:41 by marsoare         ###   ########.fr       */
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

void	valid_map(t_game *game)
{
	if (!game->map.str[0])
		error_msg("Map is empty!\n");
	if (!map_retangular(game->map))
		error_msg("Map is not retangular!\n");
	game->map.width = game->map.cols * SIZE;
	game->map.height = game->map.rows * SIZE;
}