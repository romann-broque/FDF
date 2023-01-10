/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 13:10:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_vertex_map(const t_map *map)
{
	t_vertex **const	vertex_map = map->vertex;
	const size_t		y_size = map->y_size;
	size_t				i;

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
	free_vertex_map(map);
}
