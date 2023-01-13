/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 16:11:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_vertex(t_vertex *vertex, const size_t y_index, const size_t x_index, const size_t zoom)
{
	vertex->x += x_index * zoom;
	vertex->y += y_index * zoom;
}

void	zoom(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			zoom_vertex(&(map->vcpy[i][j]), i, j, map->zoom);
			++j;
		}
		++i;
	}
}
