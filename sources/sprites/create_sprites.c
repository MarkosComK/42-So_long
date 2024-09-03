/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:40:26 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 20:40:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_img	*create_sprite(t_game *game, char *sprite_path)
{
	t_img	*sprite;

	sprite = (t_img *)ft_calloc(1, sizeof(t_img ));
	/* to do 
	if (!sprite)
	{
		free(sprite_path);
		gameover(game);
		return (NULL);
	}
	*/
	sprite->ptr = mlx_xpm_file_to_image(game->mlx, sprite_path, &sprite->w,
			&sprite->h);
	/* to do 
	if (!sprite->img)
	{
		ft_printf("Failed to load image: %s\n", sprite_path);
		free(sprite);
		free(sprite_path);
		gameover(game);
		return (NULL);
	}
	*/
	sprite->addr = mlx_get_data_addr(sprite->ptr, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
	return (sprite);
}
