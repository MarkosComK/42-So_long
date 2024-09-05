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

void	ft_bottleadd_back(t_bottle **lst, t_bottle *n_node)
{
	t_bottle	*last;

	if (!(*lst))
	{
		*lst = n_node;
		return ;
	}
	last = ft_bottlelast(*lst);
	last -> next = n_node;
}
