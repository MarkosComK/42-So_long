/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:48:32 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 11:59:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

char	*randomize_floor(int x, int y, t_map map)
{
	char	*floor;
	int		value;

	floor = FLOOR0;
	value = rand() % 100;
	if (value >= 0 && value <= 70)
		floor = FLOOR0;
	else if (value >= 80 && value <= 90)
		floor = FLOOR2;
	else if (value >= 90 && value <= 93)
		floor = FLOOR4;
	else if ((value && x == 1) || (value && x == map.cols - 2)
		|| (value && y == 1) || (value && y == map.rows - 2))
		floor = FLOOR1;
	return (floor);
}

t_pos	randomize_pos(t_pos pos, char **map, t_pos p_pos, t_game *game)
{
	t_pos	value;
	int		direction;
	int		dx[4];
	int		dy[4];

	direction = rand() % 4;
	dx[0] = 0;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = -1;
	dy[0] = -1;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = 0;
	value.x = pos.x + dx[direction];
	value.y = pos.y + dy[direction];
	if (map[value.y][value.x] == '1')
		value = pos;
	if (value.x == p_pos.x && value.y == p_pos.y)
	{
		game->player.death = 1;
		ft_printf(RED "You have ben caught!\n" DEFAULT);
	}
	return (value);
}
