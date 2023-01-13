/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 15:30:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	transform_map(t_map *map)
{
	altitude(map);
	zoom(map);
	center(map, WIDTH / 2, HEIGHT / 2);
	rotate(map);
}
