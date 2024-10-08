/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:10:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 16:58:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	destroy_sprite(t_img **sprite, void *mlx)
{
	if (*sprite)
	{
		if ((*sprite)->ptr)
		{
			mlx_destroy_image(mlx, (*sprite)->ptr);
			(*sprite)->ptr = NULL;
		}
		free(*sprite);
		*sprite = NULL;
	}
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (map.data[i])
		free(map.data[i++]);
	free(map.data);
}

void	free_tiles(t_map map)
{
	int	i;

	i = 0;
	while (map.tiles[i])
		free(map.tiles[i++]);
	free(map.tiles);
}

void	free_bottles(t_enemy *bottles)
{
	t_enemy	*tmp;

	tmp = bottles;
	while (tmp)
	{
		tmp = bottles -> next;
		free(bottles);
		bottles = tmp;
	}
}

void	free_holes(t_hole *holes)
{
	t_hole	*tmp;

	tmp = holes;
	while (tmp)
	{
		tmp = holes -> next;
		free(holes);
		holes = tmp;
	}
}
