/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 18:43:33 by rbroque          ###   ########.fr       */
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

void	init_vertex_map(t_vertex ***vertex, const size_t x_size, const size_t y_size)
{
	size_t	i;

	*vertex = (t_vertex **)ft_calloc(y_size, sizeof(t_vertex *));
	if (*vertex != NULL)
	{
		i = 0;
		while (i < y_size)
		{
			(*vertex)[i] = (t_vertex *)ft_calloc(x_size, sizeof(t_vertex));
			if ((*vertex)[i] == NULL)
			{
				destroy_vertex_map(vertex);
				return ;
			}
			++i;
		}
	}
}

void	cpy_vertex_map(t_vertex **vdest, t_vertex **vsrc, const size_t x_size, const size_t y_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < y_size)
	{
		j = 0;
		while (j < x_size)
		{
			vdest[i][j] = vsrc[i][j];
			++j;
		}
		++i;
	}
}

static void	dup_vertex_map(t_vertex ***vcpy, t_vertex **v_orig, const size_t x_size, const size_t y_size)
{
	init_vertex_map(vcpy, x_size, y_size);
	if (*vcpy != NULL)
		cpy_vertex_map(*vcpy, v_orig, x_size, y_size);
}

void	init_map(t_map *map, char ***parsing)
{
	map->x_size = get_x_size(parsing);
	map->y_size = get_y_size(parsing);
	printf("x_size --> %zu\n", map->x_size);
	printf("y_size --> %zu\n", map->y_size);
	map->x_angle = X_ANGLE;
	map->y_angle = Y_ANGLE;
	map->z_angle = Z_ANGLE;
	map->zoom = ZOOM;
	map->altitude = ALTITUDE;
	init_vertex_map(&map->vertex, map->x_size, map->y_size);
	if (map->vertex != NULL)
		fill_map(map, parsing);
	dup_vertex_map(&map->vcpy, map->vertex, map->x_size, map->y_size);
}
