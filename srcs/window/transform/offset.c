/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:03:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 18:27:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	offset_vertex_x(t_map *map, t_vertex *vertex)
{
	const int	x_shift = ((map->x_size - 1) * ZOOM) / 2;

	vertex->x += map->center.x - x_shift;
}

static void	offset_vertex_y(t_map *map, t_vertex *vertex)
{
	const int	y_shift = ((map->y_size - 1) * ZOOM) / 2;

	vertex->y += map->center.y - y_shift;
}

void	offset(t_map *map, const int x_offset, const int y_offset)
{
	size_t	i;
	size_t	j;

	map->center.x = x_offset;
	map->center.y = y_offset;
	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			offset_vertex_x(map, &(map->vcpy[i][j]));
			offset_vertex_y(map, &(map->vcpy[i][j]));
			++j;
		}
		++i;
	}
}
