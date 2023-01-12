/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 14:34:28 by rbroque          ###   ########.fr       */
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
			zoom_vertex(&(map->vcpy[i][j]), i, j);
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
			offset_vertex(&(map->vcpy[i][j]), x_offset, y_offset);
			++j;
		}
		++i;
	}
}

// ALTITUDE

static void	altitude_vertex(t_vertex *v1, t_vertex *v2)
{
	(void)v1;
	(void)v2;
}

static void	altitude(const t_map *map)
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
				altitude_vertex(&map->vcpy[i][j], &map->vcpy[i][j + 1]);
			if (i < map->y_size - 1)
				altitude_vertex(&map->vcpy[i][j], &map->vcpy[i + 1][j]);
			++j;
		}
		++i;
	}
}

// PERSP

static void	persp_vertex(const t_map *map, t_vertex *v)
{
	const float	angle = map->angle;
	const int	x_tmp = v->x;
	const int	y_tmp = v->y;

	v->x = x_tmp * cos(angle) - sin(angle) * y_tmp;
	v->y = x_tmp * sin(angle) + cos(angle) * y_tmp;
}

static void	persp(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			persp_vertex(map, &map->vcpy[i][j]);
			++j;
		}
		++i;
	}
}

void	transform_map(const t_map *map)
{
	altitude(map);
	zoom(map);
	persp(map);
	offset(map, WIDTH / 2, HEIGHT / 2);
}
