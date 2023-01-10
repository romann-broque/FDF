/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:27:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 14:08:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_vertex(t_data *data, t_vertex *vertex)
{
	put_pixel(data, vertex->x, vertex->y, vertex->color);
}

void	print_map(t_data *data, const t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			print_vertex(data, &map->vertex[i][j]);
			++j;
		}
		++i;
	}
}
