/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:38:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/06/15 22:10:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		count_lines(char *path)
{
	int		count;
	char	*str;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
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

void	init_map(t_map *map)
{
	map->map = NULL;
	map->img = NULL;
	map->columns = 0;
	map->lines = 0;
	map->width = 0;
	map->height = 0;
}

void	set_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*str;

	init_map(map);
	fd = open(path, O_RDONLY);
	map->lines = count_lines(path);
	map->map = malloc(sizeof(char **) * map->lines);
	i = 0;
	while ((str = get_next_line(fd))) 
	{
		map->map[i] = malloc(sizeof(char *) * ft_strlen(str));
		map->map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	map->width = 16 * ft_strlen(map->map[0]);
	map->height = 16 * map->lines;
	map->columns = ft_strlen(map->map[0]);
	close(fd);
}

void	draw_map(t_game game, t_map *map)
{
	t_img	img;
	int	i;
	int	j;
	int *w, *h;
	int wi, he;
	wi = 16;
	he = 20;
	w = &wi;
	h = &he;

	i = -1;
	img.img = mlx_xpm_file_to_image(game.mlx, "./assets/chort_run_anim_f1.xpm", w, h);
	while (map->map[i])
	{
		j = i + 1;
		while (map->map[j])
		{
			mlx_put_image_to_window(game.mlx, game.win, img.img, 16*i, 16*j);
			j++;
		}
		i++;
	}
}

void	game_start(char *path, t_game *game)
{
	t_map	map;
	//map = malloc(sizeof(t_map));
	set_map(path, &map);
	game->mlx = mlx_init();
	ft_printf("%s", map.map[0]);
	ft_printf("%i", map.width);
	t_img	img;
	int	i;
	int	j;
	int *w, *h;
	int wi, he;
	wi = 16;
	he = 20;
	w = &wi;
	h = &he;

	i = -1;
	img.img = mlx_xpm_file_to_image(game->mlx, "./assets/character/chort_run_anim_f1.xpm", w, h);
	while (map.map[i])
	{
		j = i + 1;
		while (map.map[j])
		{
			mlx_put_image_to_window(game->mlx, game->win, img.img, 16*i, 16*j);
			j++;
		}
		i++;
	}
	game->win = mlx_new_window(game->mlx, map.width, map.height, "so_long");
}

