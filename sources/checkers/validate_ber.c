/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:53:12 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 12:09:03 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	validate_ber(char *path)
{
	size_t		len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".ber", 4))
		return (true);
	return (false);
}
