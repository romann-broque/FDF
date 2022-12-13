/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/13 02:41:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	link_pos(t_pos *pos1, t_pos *pos2, t_win *window, unsigned int color)
{
	int	max_z;

	if (pos2 != NULL)
	{
		max_z = get_max(pos1->z, pos2->z);
	//	if (pos1->x >= 0 && pos1->x < HEIGHT && pos1->y >= 0 && pos1->y < WIDTH
	//		&& pos2->x < HEIGHT && pos1->x >= 0 && pos2->y < WIDTH && pos2->y >= 0)
			print_line(pos1, pos2, window->data, color + max_z * BLUE);
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
			if (pos_array[y + 1] != NULL)
				link_pos(curr_pos, pos_array[y + 1][x], window, color);
			++x;
		}
		++y;
	}
}
