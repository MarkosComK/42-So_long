/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:02:59 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 14:26:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	put_pixel(t_img *sprite, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= sprite->w|| y < 0 || y >= sprite->h)
	{
		ft_printf("Sprite: %p\n", sprite);
		ft_printf("Error: Attempt to draw outside the image bounds (%d, %d)\n",
			x, y);
		return ;
	}
	dst = sprite->addr + (y * sprite->line_len + x * (sprite->bpp
				/ 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_in_pixel(t_img *sprite, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(sprite->addr + (y * sprite->line_len + x
				* (sprite->bpp / 8)));
	return (color);
}
