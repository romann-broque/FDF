/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 12:41:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_vertex_map(t_vertex ****vertex_map)
{
	size_t		i;
	size_t		j;
	t_vertex	***v_map;

	v_map = *vertex_map;
	if (v_map != NULL)
	{
		i = 0;
		while (v_map[i] != NULL)
		{
			j = 0;
			while (v_map[i][j] != NULL)
			{
				free(v_map[i][j]);
				++j;
			}
			free(v_map[i]);
			++i;
		}
		free(v_map);
		v_map = NULL;
	}
}

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
			if (map->vertex[i][j] == NULL)
			{
				destroy_vertex_map(&map->vertex);
				return ;
			}
			++j;
		}
		++i;
	}
}

void	init_vertex_map(t_map *map, const size_t x_size, const size_t y_size)
{
	size_t	i;

	map->vertex = (t_vertex ***)ft_calloc(y_size + 1, sizeof(t_vertex **));
	if (map->vertex != NULL)
	{
		i = 0;
		while (i < y_size)
		{
			map->vertex[i] = (t_vertex **)ft_calloc(x_size + 1, sizeof(t_vertex *));
			if (map->vertex[i] == NULL)
			{
				destroy_vertex_map(&map->vertex);
				return ;
			}
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
		if (map->vertex != NULL)
			print_map(map);
	}
}
