/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:25:01 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 19:25:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

BOOL	valid_ber(char *path)
{
	size_t		len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".ber", 4))
		return (true);
	return (false);
}