/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:58:32 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 14:24:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char *msg)
{
	ft_printf("ERROR\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.data[i])
	{
		ft_printf("%s\n", game->map.data[i]);
		i++;
	}
}
