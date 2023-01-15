/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 19:23:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_vertex(const t_map *map, t_vertex *v)
{
	const double	x_angle = map->x_angle;
	const double	y_angle = map->y_angle;
	const double	z_angle = map->z_angle;
	const float		x_tmp = v->x;
	const float		y_tmp = v->y;

	v->x = x_tmp * cos(y_angle) * cos(z_angle) - y_tmp * cos(y_angle) * sin(z_angle);
	v->y = x_tmp * cos(x_angle) * sin(z_angle) + y_tmp * cos(x_angle) * cos(z_angle);
}

static void	rotate_map(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			rotate_vertex(map, &map->vcpy[i][j]);
			++j;
		}
		++i;
	}
}

void	offset(t_map *map, const int x_offset, const int y_offset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			map->vcpy[i][j].x += x_offset;
			map->vcpy[i][j].y += y_offset;
			++j;
		}
		++i;
	}
}

void	rotate(t_map *map)
{
	offset(map, -map->center.x, -map->center.y);
	rotate_map(map);
	offset(map, map->center.x, map->center.y);
}
