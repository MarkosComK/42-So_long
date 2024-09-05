/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:48:32 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/04 14:48:50 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*randomize_floor(int x, int y, t_map map)
{
	char	*floor;
	int		value;

	floor = FLOOR0;
	value = rand() % 100;
	ft_printf("value %i\n", value);
	if (value >= 0 && value <= 60)
		floor = FLOOR0;
	else if (value >= 70 && value <= 80)
		floor = FLOOR2;
	else if (value >= 80 && value <= 85)
		floor = FLOOR3;
	else if ((value && x == 1) || (value && x == map.cols - 2)
		|| (value && y == 1) || (value && y == map.rows - 2) )
		floor = FLOOR1;
	return (floor);
}
