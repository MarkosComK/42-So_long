/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:33:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/03 13:38:28 by marsoare         ###   ########.fr       */
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

void	set_map_tiles(t_game *game)
{
	int	i;

	i = 0;
	game->map.tiles = (t_tile **)ft_calloc(game->map.rows + 1, sizeof(t_tile *)
			* SZ);
	/* to do 
	if (!game->map.tiles)
		tiles_error(0, game);
	*/
	while (i < game->map.rows)
	{
		game->map.tiles[i] = (t_tile *)ft_calloc(sizeof(t_tile *) * SZ,
			ft_strlen(game->map.data[i]) + 1);
		/* to do
		if (!game->map.tiles[i++])
			tiles_error(0, game);
		*/
		i++;
	}
}

void    set_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(map_path, O_RDONLY);
	game->map.rows = count_lines(map_path);
	game->map.data = ft_calloc(sizeof(char **), game->map.rows + 1);
	i = 0;
	while ((str = get_next_line(fd))) 
	{
		game->map.data[i] = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
		ft_strlcpy(game->map.data[i], str, ft_strlen(str));
		free(str);
		i++;
	}
	close(fd);
	set_map_tiles(game);
}
