/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:23:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 19:25:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char *msg)
{
	ft_printf("ERROR\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	char	*path;

	path = av[1];
	if (ac != 2)
		error_msg("Usage: ./so_long ./maps/map.ber");
	else if (valid_ber(path))
	{
		error_msg("MAP ISN'T A .ber FILE");
		exit(1);
	}
	//init_game(path);
	return (0);
}
