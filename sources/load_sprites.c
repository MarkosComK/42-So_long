/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:40:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 17:14:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
t_img   new_file_img(char *path, t_game *game)
{
    t_img   image;

    image.win = game->win;
    image.mlx = game->mlx;
    image.ptr = mlx_xpm_file_to_image(image.mlx, path, &image.w, &image.h);
    if (!image.ptr)
        error_msg("File could not be read!\n");
    else
        image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
         &(image.line_len), &(image.endian));
    return (image);
}
*/
/*
unsigned int    get_pixel_img(t_img img, int x, int y)
{
    return (*(unsigned int) ((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}
*/
