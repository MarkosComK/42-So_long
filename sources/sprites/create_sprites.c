/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:40:26 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 20:59:17 by marsoare         ###   ########.fr       */
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

void	create_map(t_game *game)
{
	int			y;
	int			x;
	t_img		*sprite;
	char		*sprite_path;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			sprite_path = get_sprite_path(game, game->map.tiles[y][x].type, x, y);
	/* to do 
			if (!sprite_path)
			{
				gameover(game);
			}
	*/
			game->map.tiles[y][x].sprite_path = ft_strdup(sprite_path);
			sprite = create_sprite(game, sprite_path);
			create_world(sprite, game, x, y);
			mlx_destroy_image(game->mlx, sprite->ptr);
		}
	}
}

char	*get_sprite_path(t_game *game, char c, int x, int y)
{
	char	*path;
	(void) game;

	ft_printf("cols: %i x: %i\n", game->map.cols, x);
	path = NULL;
	if (c == '1' && x == 0 && y == 0)
		path = WALL_LT;
	else if (c == '1' && x == game->map.cols - 1 && y == 0)
		path = WALL_RT;
	else if (c == '1' && x == game->map.cols - 1 && y == game->map.rows - 1)
		path = WALL_RT;
	else if (c == '1')
		path = WALL;
	else if (c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M')
		path = FLOOR0;
	/* to do 
	if (!path)
	{
		ft_printf("Failed to allocate path for character: %c\n", c);
		gameover(game);
	}
	*/
	return (path);
}

void	create_world(t_img *sprite, t_game *game, int posx, int posy)
{
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	trans_color;

	trans_color = 0xFFC0CB;
	y = -1;
	while (++y < sprite->h)
	{
		x = -1;
		while (++x < sprite->w)
		{
			color = get_color_in_pixel(sprite, x, y);
			if (color != trans_color)
			{
				put_pixel(game->world, posx * SZ + x, posy * SZ + y, color);
			}
		}
	}
}
