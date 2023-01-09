/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 15:59:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_vertex_map(t_vertex ***vertex_map)
{
	size_t	i;
	size_t	j;

	if (vertex_map != NULL)
	{
		i = 0;
		while (vertex_map[i] != NULL)
		{
			j = 0;
			while (vertex_map[i][j] != NULL)
			{
				free(vertex_map[i][j]);
				++j;
			}
			free(vertex_map[i]);
			++i;
		}
		free(vertex_map);
	}
}

void	free_map(t_map *map)
{
	free_vertex_map(map->vertex);
}
