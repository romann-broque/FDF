/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 15:36:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_altitude(const char *format, int *minz, int *maxz)
{
	const int	new_z = ft_atoi(format);

	if (*minz > new_z)
		*minz = new_z;
	if (*maxz < new_z)
		*maxz = new_z;
	return (new_z);
}

static bool	is_prefix_valid(const char *format)
{
	return (ft_strncmp(format, COLOR_PREFIX, ft_strlen(COLOR_PREFIX)) == 0);
}

static float	get_rad(const int alt, const int minz, const int maxz)
{
	t_color	color;
	float	rad;

	rad = (float)(alt - minz) / (float)(maxz - minz);
	if (rad < 0.25)
	{
		color.red = 0;
		color.green = (int)(4 * rad * UCHAR_MAX);
		color.blue = UCHAR_MAX;
	}
	else if (rad < 0.5)
	{
		color.red = 0;
		color.green = UCHAR_MAX;
		color.blue = (int)((1 - 4 * (rad - 0.25)) * UCHAR_MAX);
	}
	else if (rad < 0.75)
	{
		color.red = (int)(4 * (rad - 0.5) * UCHAR_MAX);
		color.green = UCHAR_MAX;
		color.blue = 0;
	}
	else
	{
		color.red = UCHAR_MAX;
		color.green = (int)((1 - 4 * (rad - 0.75)) * UCHAR_MAX);
		color.blue = 0;
	}
	return (sum_color(color));
}

static float	get_color(const int alt, const char *format, const int minz, const int maxz)
{
	float	color;

	format += abs_index(format, SEPARATOR) + 1;
	if (is_prefix_valid(format) == true)
		color = ft_atoi_base(format + ft_strlen(COLOR_PREFIX), HEX_BASE);
	else if (minz != maxz)
		color = get_rad(alt, minz, maxz); // protect agasint maxz == 0
	else
		color = WHITE;
	return (color);
}

void	set_vertex(t_vertex *vertex,
				const float x, const float y, const float z, const float color)
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
	const int	new_z = get_altitude(format, &map->minz, &map->maxz);

	set_vertex(&map->vertex[y][x], new_x, new_y, new_z, WHITE);
}

void	set_color(t_vertex *vertex, const char *format, const int minz, const int maxz)
{
	vertex->color = get_color(vertex->z, format, minz, maxz);
}
