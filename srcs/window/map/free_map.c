/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 13:59:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_vertex_map(t_vertex **vertex_map, const size_t y_size)
{
	size_t	i;

	if (vertex_map != NULL)
	{
		i = 0;
		while (i < y_size)
		{
			free(vertex_map[i]);
			++i;
		}
		free(vertex_map);
	}
}

void	free_map(t_map *map)
{
	free_vertex_map(map->vertex, map->y_size);
	free_vertex_map(map->vcpy, map->y_size);
}
