/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:36:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 22:39:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	if (keycode == XK_Up || keycode == XK_w)
	{
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y - 1};
		g->player.dir = MVUP;
	}
	if (keycode == XK_Down || keycode == XK_s)
	{
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y + 1};
		g->player.dir = MVDOWN;
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		g->player.next = (t_point){g->player.pos.x - 1, g->player.pos.y};
		g->player.dir = MVLEFT;
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		g->player.next = (t_point){g->player.pos.x + 1, g->player.pos.y};
		g->player.dir = MVRIGHT;
	}
	return (keycode);
}