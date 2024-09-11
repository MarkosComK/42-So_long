/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:37:28 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 20:35:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_enemy	*ft_bottlelast(t_enemy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

t_enemy	*bottle_add(t_enemy *node, int x, int y)
{
	t_enemy	*new;

	new = bottle_create(x, y);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	return (new);
}

t_enemy	*bottle_push_tail(t_enemy *stack, int x, int y)
{
	t_enemy	*new_node;
	t_enemy	*last;

	new_node = bottle_create(x, y);
	if (!new_node)
		return (NULL);
	last = ft_bottlelast(stack);
	last->next = new_node;
	return (new_node);
}

t_enemy	*bottle_create(int x, int y)
{
	t_enemy	*stack_new;

	stack_new = (t_enemy *)malloc(sizeof(t_enemy));
	if (!stack_new)
		return (NULL);
	stack_new -> sprite = NULL;
	stack_new -> current_s = 0;
	stack_new -> sprite_idle[0] = ENEMY_0;
	stack_new -> sprite_idle[1] = ENEMY_1;
	stack_new -> sprite_idle[2] = ENEMY_2;
	stack_new -> sprite_idle[3] = ENEMY_3;
	stack_new -> pos = (t_pos){x, y};
	stack_new -> next = NULL;
	return (stack_new);
}

int	bottles_size(t_enemy *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}
