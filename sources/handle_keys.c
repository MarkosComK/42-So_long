/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:36:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/25 14:59:41 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.str[i])
		free(game->map.str[i++]);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->map.str);
	free(game->mlx);
	exit(0);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == XK_Up || keycode == XK_w)
	{
		ft_printf("You pressed %i", XK_Up);
	}
	if (keycode == XK_Down || keycode == XK_s)
	{
		ft_printf("You pressed %i", XK_Down);
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		ft_printf("You pressed %i", XK_Left);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		ft_printf("You pressed %i", XK_Right);
	}
	if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	return (1);
}