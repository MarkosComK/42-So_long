/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:36:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 09:52:27 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	colision_check(t_game *game, t_pos *pos, int dx, int dy);

int	key_press(int keycode, t_game *g)
{
	t_pos	*pos;

	pos = &g->player.s_pos;
	if (keycode == XK_Up || keycode == XK_w)
	{
		ft_printf("outside pos {%i, %i}\n", pos->x, pos->y);
		colision_check(g, pos, 0, -1);
	}
	if (keycode == XK_Down || keycode == XK_s)
	{
		colision_check(g, pos, 0, 1);
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		colision_check(g, pos, -1, 0);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		colision_check(g, pos, 1, 0);
	}
	if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	return (1);
}

void	colision_check(t_game *game, t_pos *pos, int dx, int dy)
{
	t_pos	new_pos;

	new_pos.x = pos->x + dx;
	new_pos.y = pos->y + dy;
	if (game->map.data[new_pos.y][new_pos.x] == '1')
		return ;
	else
	{
		game->player.s_pos.x += dx;
		game->player.s_pos.y += dy;
	}
}
