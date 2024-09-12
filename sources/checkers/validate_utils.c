/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:36:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/12 15:38:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	floodfill(t_game *game, char **matrix, t_pos cur)
{
	if (matrix[cur.y][cur.x] == '1')
		return ;
	else if (matrix[cur.y][cur.x] == 'C')
		game->path_collect++;
	else if (matrix[cur.y][cur.x] == 'E')
		game->path = 1;
	matrix[cur.y][cur.x] = '1';
	floodfill(game, matrix, (t_pos){cur.x + 1, cur.y});
	floodfill(game, matrix, (t_pos){cur.x - 1, cur.y});
	floodfill(game, matrix, (t_pos){cur.x, cur.y + 1});
	floodfill(game, matrix, (t_pos){cur.x, cur.y - 1});
}

void	map_matrix_delete(char **map_bytes)
{
	int	i;

	i = 0;
	while (map_bytes[i])
	{
		free(map_bytes[i]);
		i++;
	}
	free(map_bytes[i]);
	free(map_bytes);
}
