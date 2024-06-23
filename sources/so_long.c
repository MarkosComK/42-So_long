/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:23:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 18:45:42 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char *msg)
{
	ft_printf("Error\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}
bool valid_ber(char *path) {
  size_t len = ft_strlen(path);
  bool  result = strcmp(path + len - 4, ".ber");
  return (result);
}

int	main(int ac, char **av)
{
	char	*path;

	path = av[1];
	if (ac != 2)
		error_msg("Usage: ./so_long ./maps/map.ber\n");
	else if (!valid_ber(path))
	{
		error_msg("Map isn't a .ber file!\n");
		exit(1);
	}
	init_game(path);
	return (0);
}
