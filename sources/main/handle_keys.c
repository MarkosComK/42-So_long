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

#include "../../includes/so_long.h"

void	wall_check(t_game *game, t_pos *pos, int dx, int dy);

int	key_press(int keycode, t_game *g)
{
	t_pos	*pos;

	pos = &g->player.s_pos;
	if (keycode == XK_Up || keycode == XK_w)
	{
		wall_check(g, pos, 0, -1);
	}
	if (keycode == XK_Down || keycode == XK_s)
	{
		wall_check(g, pos, 0, 1);
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		wall_check(g, pos, -1, 0);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		wall_check(g, pos, 1, 0);
	}
	if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	return (1);
}

void	del_bottle(t_game *game, int index)
{
	t_bottle	*prev;
	t_bottle	*temp;
	int			i;

	temp = game->bottle;
	i = 0;
	if (index == 0 && temp != NULL)
	{
		game->bottle = temp->next;
		free(temp);
		return ;
	}
	while (i < index && temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		i++;
	}
	if (temp != NULL)
	{
		prev->next = temp->next;
		free(temp);
	}
	return ;
}

void	bottle_check(t_game *game, t_pos *pos)
{
	t_pos		new_pos;
	t_bottle	*bottles;
	int			index;

	new_pos = (t_pos){pos->x, pos->y};
	bottles = game->bottle;
	index = 0;
	while (bottles)
	{
		if (new_pos.x == bottles->pos.x && new_pos.y == bottles->pos.y)
		{
			game->player.points++;
			del_bottle(game, index);
			return ;
		}
		bottles = bottles -> next;
		index++;
	}
}

void	wall_check(t_game *game, t_pos *pos, int dx, int dy)
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
		game->player.moves++;
		ft_printf("moves: %i\n", game->player.moves);
	}
}

void	exit_check(t_game *game, t_pos *pos)
{
	t_exit	*exit;

	exit = &game->exit;
	if (exit->open)
	{
		if (pos->x == exit->pos.x && pos->y == exit->pos.y)
			quit(game);
	}
}