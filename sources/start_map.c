/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:33:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 20:38:24 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_map()
{

}

int		count_lines(char *map_path)
{
	int		count;
	char	*str;
	int		fd;

	count = 0;
	fd = open(map_path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void    set_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(map_path, O_RDONLY);
	game->map.rows = count_lines(map_path);
	game->map.str = ft_calloc(sizeof(char **), game->map.rows + 1);
	i = 0;
	while ((str = get_next_line(fd))) 
	{
		game->map.str[i] = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
		ft_strlcpy(game->map.str[i], str, ft_strlen(str));
		free(str);
		i++;
	}
	close(fd);
}
