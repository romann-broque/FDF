/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:27:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 16:02:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_vertex(t_vertex *vertex)
{
	printf("%d ", vertex->z);
}

void	print_map(const t_map *map)
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
