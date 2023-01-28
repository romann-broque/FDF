/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 00:48:18 by rbroque          ###   ########.fr       */
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

void	set_vertex(t_vertex *vertex,
				const float x, const float y, const float z)
{
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	vertex->color.sum = WHITE;
	get_color_comp(&vertex->color);
}

void	get_vertex(t_map *map, const int x, const int y, const char *format)
{
	const int	new_x = x;
	const int	new_y = y;
	const int	new_z = get_altitude(format, &map->minz, &map->maxz);

	set_vertex(&map->vertex[y][x], new_x, new_y, new_z);
}
