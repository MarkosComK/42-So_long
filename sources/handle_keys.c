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

int	key_press(int keycode, t_game *g)
{
	if (keycode == XK_Up || keycode == XK_w)
	{
		ft_printf("You pressed %i\n", XK_Up);
	}
	if (keycode == XK_Down || keycode == XK_s)
	{
		ft_printf("You pressed %i\n", XK_Down);
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		ft_printf("You pressed %i\n", XK_Left);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		g->player.s_pos.x++;
		ft_printf("You pressed %i\n", XK_Right);
		ft_printf("game s_pos.x: %i\n", g->player.s_pos.x);
	}
	if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	return (1);
}
