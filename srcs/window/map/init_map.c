/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 13:06:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_vertex_map(t_vertex ***v_map)
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

static void	fill_map(t_map *map, char ***parsing)
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
			get_vertex(&map->vertex[i][j], j, i, parsing[i][j]);
			++j;
		}
		++i;
	}
}

void	init_vertex_map(t_map *map)
{
	const size_t	x_size = map->x_size;
	const size_t	y_size = map->y_size;
	size_t			i;

	map->vertex = (t_vertex **)ft_calloc(y_size, sizeof(t_vertex *));
	if (map->vertex != NULL)
	{
		i = 0;
		while (i < y_size)
		{
			map->vertex[i] = (t_vertex *)ft_calloc(x_size, sizeof(t_vertex));
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
	map->x_size = get_x_size(parsing);
	map->y_size = get_y_size(parsing);
	init_vertex_map(map);
	if (map->vertex != NULL)
	{
		fill_map(map, parsing);
		if (map->vertex != NULL)
			print_map(map);
	}
}
