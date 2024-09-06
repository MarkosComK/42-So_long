/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:37:28 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/05 19:37:38 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bottle	*ft_bottlelast(t_bottle *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

t_bottle	*bottle_add(t_bottle *node, int x, int y)
{
	t_bottle	*new;

	new = bottle_create(x, y);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	return (new);
}

t_bottle	*bottle_push_tail(t_bottle *stack, int x, int y)
{
	t_bottle	*new_node;
	t_bottle	*last;

	new_node = bottle_create(x, y);
	if (!new_node)
		return (NULL);
	last = ft_bottlelast(stack);
	last->next = new_node;
	return (new_node);
}

t_bottle	*bottle_create(int x, int y)
{
	t_bottle	*stack_new;

	stack_new = (t_bottle *)malloc(sizeof(t_bottle));
	if (!stack_new)
		return (NULL);
	stack_new -> sprite = NULL;
	stack_new -> pos = (t_pos){x, y};
	stack_new -> next = NULL;
	return (stack_new);
}

int	bottles_size(t_bottle *lst)
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
