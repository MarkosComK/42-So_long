/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:30:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 20:01:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	set_map(&game, map_name);
}