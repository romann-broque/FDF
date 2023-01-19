/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/19 11:51:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_altitude(const char *format, int *minz)
{
	const int	new_z = ft_atoi(format);

	if (*minz > new_z)
		*minz = new_z;
	return (new_z);
}

static bool	is_prefix_valid(const char *format)
{
	return (ft_strncmp(format, COLOR_PREFIX, ft_strlen(COLOR_PREFIX)) == 0);
}

static int	get_color(const int alt, const char *format, const int minz)
{
	uint	color;

	format += abs_index(format, SEPARATOR) + 1;
	if (is_prefix_valid(format) == true)
		color = ft_atoi_base(format + ft_strlen(COLOR_PREFIX), HEX_BASE);
	else
		color = (alt - minz);
	(void)minz;
	return (color);
}

void	set_vertex(t_vertex *vertex,
				const float x, const float y, const float z, const int color)
{
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	vertex->color = color;
}

void	get_vertex(t_map *map, const size_t x, const size_t y, const char *format)
{
	const int	new_x = (int)x;
	const int	new_y = (int)y;
	const int	new_z = get_altitude(format, &map->minz);

	set_vertex(&map->vertex[y][x], new_x, new_y, new_z, WHITE);
}

void	set_color(t_vertex *vertex, const char *format, const int minz)
{
	vertex->color = get_color(vertex->z, format, minz);
}
