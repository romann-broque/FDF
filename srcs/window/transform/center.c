/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:03:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 18:20:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_center(t_map *map, const int x_offset, const int y_offset)
{
	map->center.x = x_offset;
	map->center.y = y_offset;
}

static void	center_vertex(t_map *map, t_vertex *vertex)
{
	const int	x_shift = ((map->x_size - 1) * map->zoom) / 2;
	const int	y_shift = ((map->y_size - 1) * map->zoom) / 2;

	vertex->x += map->center.x - x_shift;
	vertex->y += map->center.y - y_shift;
}

void	center(t_map *map, const int x_offset, const int y_offset)
{
	size_t	i;
	size_t	j;

	set_center(map, x_offset, y_offset);
	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			center_vertex(map, &(map->vcpy[i][j]));
			++j;
		}
		++i;
	}
}
