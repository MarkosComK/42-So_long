/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_holes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:35:47 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/11 17:12:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_hole *ft_holelast(t_hole *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

t_hole	*hole_add(t_hole *node, int x, int y)
{
	t_hole	*new;

	new = hole_create(x, y);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	return (new);
}

t_hole	*hole_push_tail(t_hole *stack, int x, int y)
{
	t_hole	*new_node;
	t_hole	*last;

	new_node = hole_create(x, y);
	if (!new_node)
		return (NULL);
	last = ft_holelast(stack);
	last->next = new_node;
	return (new_node);
}

t_hole	*hole_create(int x, int y)
{
	t_hole	*stack_new;

	stack_new = (t_hole *)malloc(sizeof(t_hole));
	if (!stack_new)
		return (NULL);
	stack_new -> sprite[0] = NULL;
	stack_new -> sprite[1] = NULL;
	stack_new -> pos = (t_pos){x, y};
	stack_new -> next = NULL;
	return (stack_new);
}

int	holes_size(t_hole *lst)
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
