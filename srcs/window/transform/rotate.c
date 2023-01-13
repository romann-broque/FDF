/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 16:07:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_vertex(const t_map *map, t_vertex *v)
{
	const double	angle = map->angle;
	const int		x_tmp = v->x;
	const int		y_tmp = v->y;

	v->x = x_tmp * cos(angle) - sin(angle) * y_tmp;
	v->y = x_tmp * sin(angle) + cos(angle) * y_tmp;
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
