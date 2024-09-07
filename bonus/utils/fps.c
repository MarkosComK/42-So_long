/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:54:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/07 17:07:40 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <time.h>

void	print_fps(clock_t current_time)
{
	static clock_t	fps_last_time = 0;
	static int	frame_count = 0;
	int fps;

	frame_count++;
	if ((current_time - fps_last_time) >= CLOCKS_PER_SEC)
	{
		fps = frame_count;
		frame_count = 0;
		fps_last_time = current_time;
		ft_printf("FPS: %d\n", fps);
	}
}
