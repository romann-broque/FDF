/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 12:41:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_vertex(const t_map *map, t_vertex *v)
{
	const float	x_tmp = v->x;
	const float	y_tmp = v->y;

	v->x = map->cosy * (x_tmp * map->cosz - y_tmp * map->sinz);
	v->y = map->cosx * (x_tmp * map->sinz + y_tmp * map->cosz);
}

static void	init_trigo(t_map *map)
{
	map->cosx = cos(map->x_angle);
	map->sinx = sin(map->x_angle);
	map->cosy = cos(map->y_angle);
	map->siny = sin(map->y_angle);
	map->cosz = cos(map->z_angle);
	map->sinz = sin(map->z_angle);
}

static void	rotate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	init_trigo(map);
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

void	rotate(t_map *map)
{
	offset(map, -map->center.x, -map->center.y);
	rotate_map(map);
	offset(map, map->center.x, map->center.y);
}
