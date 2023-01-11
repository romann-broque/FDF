/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:27:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/11 17:15:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_map(t_data *data, const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			if (j < map->x_size - 1)
				put_line(data, map->vertex[i][j], map->vertex[i][j + 1]);
			if (i < map->y_size - 1)
				put_line(data, map->vertex[i][j], map->vertex[i + 1][j]);
			++j;
		}
		++i;
	}
}

void	display_map(t_win *window)
{
	if (window->map.vertex)
	{
		print_map(&window->data, &window->map);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
	}
}
