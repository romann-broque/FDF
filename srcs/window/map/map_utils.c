/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:25:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:27:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_vertex_map(t_vertex ***v_map)
{
	size_t	i;

	if (*v_map != NULL)
	{
		i = 0;
		while ((*v_map)[i] != NULL)
		{
			free((*v_map)[i]);
			++i;
		}
		*v_map = NULL;
		free(*v_map);
	}
}

void	set_map_color(t_map *map, char ***parsing)
{
	const size_t	x_size = map->x_size;
	const size_t	y_size = map->y_size;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < y_size)
	{
		j = 0;
		while (j < x_size)
		{
			get_color(&map->vertex[i][j], parsing[i][j], map->minz, map->maxz);
			++j;
		}
		++i;
	}
}

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
