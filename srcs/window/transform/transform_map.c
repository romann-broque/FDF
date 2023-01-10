/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 14:07:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_vertex(t_vertex *vertex, const size_t y_index, const size_t x_index)
{
	vertex->x += x_index * ZOOM;
	vertex->y += y_index * ZOOM;
}

static void	zoom(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			zoom_vertex(&(map->vertex[i][j]), i, j);
			++j;
		}
		++i;
	}
}

// OFFSET

static void	offset_vertex(t_vertex *vertex, const int x_offset, const int y_offset)
{
	vertex->x += x_offset;
	vertex->y += y_offset;
}

static void	offset(const t_map *map, const int x_offset, const int y_offset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			offset_vertex(&(map->vertex[i][j]), x_offset, y_offset);
			++j;
		}
		++i;
	}
}

void	transform_map(const t_map *map)
{
	offset(map, WIDTH / 4, HEIGHT / 4);
	zoom(map);
}
