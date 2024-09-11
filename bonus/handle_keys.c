/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:36:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 19:41:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	wall_check(t_game *game, t_pos *pos, t_pos xy);

int	key_press(int keycode, t_game *g)
{
	t_pos	*pos;

	if (g->player.is_mov)
		return (1);
	else if (!g->player.death)
	{
		pos = &g->player.s_pos;
		if (keycode == XK_Up || keycode == XK_w)
			check_sprites(g, &g->player, (t_pos){0, -1});
		else if (keycode == XK_Down || keycode == XK_s)
			check_sprites(g, &g->player, (t_pos){0, 1});
		else if (keycode == XK_Left || keycode == XK_a)
			check_sprites(g, &g->player, (t_pos){-1, 0});
		else if (keycode == XK_Right || keycode == XK_d)
			check_sprites(g, &g->player, (t_pos){1, 0});
		else if (keycode == XK_Escape || keycode == XK_q)
			quit(g);
	}
	else if (keycode == XK_Escape || keycode == XK_q)
		quit(g);
	return (1);
}

void	del_bottle(t_game *game, int index)
{
	t_enemy	*prev;
	t_enemy	*temp;
	int			i;

	temp = game->enemy;
	i = 0;
	if (index == 0 && temp != NULL)
	{
		game->enemy = temp->next;
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
	t_enemy		*enemy;
	int			index;

	new_pos = (t_pos){pos->x, pos->y};
	enemy = game->enemy;
	index = 0;
	while (enemy)
	{
		if (new_pos.x == enemy->pos.x && new_pos.y == enemy->pos.y)
		{
			game->player.points++;
			del_bottle(game, index);
			return ;
		}
		enemy = enemy -> next;
		index++;
	}
}

void	wall_check(t_game *game, t_pos *pos, t_pos xy)
{
	t_pos	new_pos;

	new_pos.x = pos->x + xy.x;
	new_pos.y = pos->y + xy.y;
	if (game->map.data[new_pos.y][new_pos.x] == '1')
		return ;
	else
	{
		game->player.s_pos.x += xy.x;
		game->player.s_pos.y += xy.y;
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
