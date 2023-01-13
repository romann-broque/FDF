/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:48:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 16:49:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	offset(t_map *map, const int x_offset, const int y_offset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->y_size)
	{
		j = 0;
		while (j < map->x_size)
		{
			map->vcpy[i][j].x += x_offset;
			map->vcpy[i][j].y += y_offset;
			++j;
		}
		++i;
	}
}
