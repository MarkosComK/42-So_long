/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:06:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 18:34:23 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_collectibles(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(game->map.data[i])
	{
		j = 0;
		while(game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'C')
				ft_printf("%c", game->map.data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
