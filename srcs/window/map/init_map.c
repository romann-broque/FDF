/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 13:46:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// GET_SIZE //

static size_t	get_size_strs(char **parsed_line)
{
	size_t	size;

	size = 0;
	while (parsed_line[size] != NULL)
		++size;
	return (size);
}

static size_t	get_x_size(char ***parsing)
{
	size_t	i;
	size_t	curr_size;
	size_t	size;

	size = 0;
	i = 0;
	while (parsing[i] != NULL)
	{
		curr_size = get_size_strs(parsing[i]);
		if (size < curr_size)
			size = curr_size;
		++i;
	}
	return (size);
}

static size_t	get_y_size(char ***parsing)
{
	size_t	size;

	size = 0;
	while (parsing[size] != NULL)
		++size;
	return (size);
}

///////////////////////

// GET_DATA //

static int	get_altitude(const char *format)
{
	return (ft_atoi(format));
}

static int	get_color(const char *format)
{
	(void)format;
	return (0);
}

///////////////////////

// VERTEX //

static t_vertex	*create_vertex(const int x, const int y, const int z, const int color)
{
	t_vertex	*new;

	new = (t_vertex *)malloc(sizeof(t_vertex));
	if (new != NULL)
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->color = color;
	}
	return (new);
}

static t_vertex	*get_vertex(const size_t x, const size_t y, const char *format)
{
	const int	new_x = (int)x;
	const int	new_y = (int)y;
	const int	new_z = get_altitude(format);
	const int	color = get_color(format);

	return (create_vertex(new_x, new_y, new_z, color));
}

static void	print_vertex(t_vertex *vertex)
{
	printf("%d ", vertex->z);
}

///////////////////////

// MAP

static void	display_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->vertex[i] != NULL)
	{
		j = 0;
		while (map->vertex[i][j] != NULL)
		{
			print_vertex(map->vertex[i][j]);
			++j;
		}
		printf("\n");
		++i;
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
		display_map(map);
	}
}
