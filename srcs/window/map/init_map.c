/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 14:30:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_map(t_map *map, char ***parsing)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (parsing[i] != NULL)
	{
		j = 0;
		while (parsing[i][j] != NULL)
		{
			map->vertex[i][j] = get_vertex(j, i, parsing[i][j]);
			++j;
		}
		++i;
	}
}

void	init_vertex_map(t_map *map, const size_t x_size, const size_t y_size)
{
	size_t	i;

	map->vertex = (t_vertex ***)malloc((y_size + 1) * sizeof(t_vertex **));
	if (map->vertex != NULL)
	{
		map->vertex[y_size] = NULL;
		i = 0;
		while (i < y_size)
		{
			map->vertex[i] = (t_vertex **)malloc((x_size + 1) * sizeof(t_vertex *));
			if (map->vertex[i] != NULL)
				map->vertex[i][x_size] = NULL;
			//else
				// destroy_vertex_map(map->vertex);
			++i;
		}
	}
}

void	init_map(t_map *map, char ***parsing)
{
	const size_t	x_size = get_x_size(parsing);
	const size_t	y_size = get_y_size(parsing);

	init_vertex_map(map, x_size, y_size);
	if (map->vertex != NULL)
	{
		fill_map(map, parsing);
		print_map(map);
	}
}
