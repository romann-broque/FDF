/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 14:59:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ALTITUDE

static void	altitude_vertex(t_vertex *v, const double altitude, const double zoom)
{
	v->y += (altitude * zoom) * v->z;
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
			altitude_vertex(&map->vcpy[i][j], map->altitude, map->zoom);
			++j;
		}
		++i;
	}
}

void	transform_map(t_map *map)
{
	zoom(map);
	center(map, WIDTH / 2, HEIGHT / 2);
	rotate(map);
	altitude(map);
}
