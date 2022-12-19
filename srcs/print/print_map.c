/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 00:16:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	link_pos(t_pos *pos1, t_pos *pos2, t_win *window, unsigned int color)
{
	int	max_z;

	if (pos2 != NULL)
	{
		max_z = get_max(pos1->z, pos2->z);
		print_line(pos1, pos2, window->data, color + window->data->contrast * max_z * BLUE);
	}
}

void	print_map(t_pos ***pos_array, t_win *window, unsigned int color)
{
	size_t	x;
	size_t	y;
	t_pos	*curr_pos;

	y = 0;
	while (pos_array[y] != NULL)
	{
		x = 0;
		while (pos_array[y][x] != NULL)
		{
			curr_pos = pos_array[y][x];
			link_pos(curr_pos, pos_array[y][x + 1], window, color);
			if (pos_array[y + 1] != NULL && get_pos_array_size(pos_array[y + 1]) >= x)
				link_pos(curr_pos, pos_array[y + 1][x], window, color);
			++x;
		}
		++y;
	}
}
