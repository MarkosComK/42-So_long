/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:22:41 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/23 17:46:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_layout	ft_newlayout(void)
{
	t_layout	lay;

	lay.n_row = 0;
	lay.n_col = 0;
	lay.n_exit = 0;
	lay.n_player = 0;
	lay.n_gh = 0;
	lay.n_collect = 0;
	return (lay);
}

int	error_msg(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str);
	ft_printf("Error\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}

char    **check_params(int ac, char **av, t_layout *layout)
{
    int		fd;

	if (ac != 2)
		error_msg("Invalid number of arguments!", NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", NULL);
	if (ft_strrncmp(av[1], ".ber", 4))
		error_msg("Invalid file type!", NULL);
	return (check_map(fd, layout));
}
t_error	ft_newmap_error(void)
{
	t_error	map_err;

	map_err.inv_borders = 0;
	map_err.inv_char = 0;
	map_err.inv_n_exits = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_rowlen = 0;
	map_err.inv_n_players = 0;
	map_err.inv_n_ghosts = 0;
	return (map_err);
}
void	ft_readlayout(int fd, t_error *map_err, t_layout *lay, char **map_str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				error_msg_params("Map is empty!", NULL);
			else
				ft_checklayout(last_line, map_err, lay, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_checklayout(line, map_err, lay, !lay->n_row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strenlarge(*map_str, line);
		lay->n_row++;
	}
}
int	ft_print_map_error(t_error *map_err, char **map_str)
{
	if (map_err->inv_rowlen)
		error_msg_params("Map must be rectangular!", map_str);
	if (map_err->inv_borders)
		error_msg_params("Map must be surrounded by walls!", map_str);
	if (map_err->inv_char)
		error_msg_params("Unexpected char(s) in map!", map_str);
	if (map_err->inv_n_exits)
		error_msg_params("Invalid number of exits!", map_str);
	if (map_err->inv_n_players)
		error_msg_params("Invalid number of players!", map_str);
	if (map_err->inv_n_collect)
		error_msg_params("There should be at least one collectible!", map_str);
	return (0);
}

char	**check_map(int fd, t_layout *layout)
{
	char	*map_str;
	char	**map;
	t_error	map_err;

	map_str = NULL;
	map = NULL;
	map_err = ft_newmap_error();
	*layout = ft_newlayout();
	ft_readlayout(fd, &map_err, layout, &map_str);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg_params("Memory allocation error!", NULL);
	return (map);
}
