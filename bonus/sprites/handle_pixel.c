/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:42:43 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 20:42:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	put_pixel(t_img *sprite, int x, int y, int color)
{
	char	*dst;

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
