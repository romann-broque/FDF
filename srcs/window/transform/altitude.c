/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:55:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 11:47:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	altitude_vertex(t_vertex *v, const t_map *map)
{
	v->x += (map->altitude * map->zoom) * map->siny * v->z;
	v->y += (map->altitude * map->zoom) * v->z;
}

void	altitude(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			altitude_vertex(&map->vcpy[i][j], map);
			++j;
		}
		++i;
	}
}
