/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:34:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/09 21:12:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	ft_printf("%i\n", ft_printf("%s", "this is a string"));
	int		fd = open("./ft_atoi.c", O_RDONLY);
	char	*line;
	while((line = get_next_line(fd)))
	{
		ft_printf("%s", line);
		free(line);
	}
}
