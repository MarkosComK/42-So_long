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

char	*randomize_floor(void)
{
	char	*floor;
	int		value;

	floor = FLOOR0;
	value = rand() % 10;
	if (value >= 0 && value <= 7)
		floor = FLOOR0;
	else if (value == 9)
		floor = FLOOR1;
	else
		floor = FLOOR2;
	return (floor);
}
