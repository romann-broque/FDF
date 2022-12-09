/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/09 16:29:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_pos ***pos_array, t_win *window)
{
	size_t	x;
	size_t	y;
	int		max_z;
	t_pos	*pos1;
	t_pos	*pos2;

	y = 0;
	while (pos_array[y] != NULL)
	{
		x = 0;
		while (pos_array[y][x] != NULL)
		{
			pos1 = pos_array[y][x];
			if (pos_array[y][x + 1] != NULL)
			{
				pos2 = pos_array[y][x + 1];
				max_z = get_max(pos1->z, pos2->z);
				print_line(pos1, pos2, window->data, WHITE + max_z * BLUE);
			}
			if (pos_array[y + 1] != NULL
					&& pos_array[y + 1][x] != NULL)
			{
				pos2 = pos_array[y + 1][x];
				max_z = get_max(pos1->z, pos2->z);
				print_line(pos1, pos2, window->data, WHITE + max_z * BLUE);
			}
			++x;
		}
		++y;
	}
}
