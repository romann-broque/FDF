/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/08 00:00:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_pos ***pos_array, t_data *img)
{
	size_t	x;
	size_t	y;
	t_pos	*pos1;
	t_pos	*pos2;

	y = 0;
	while (pos_array[y] != NULL)
	{
		x = 0;
		while (pos_array[y][x] != NULL)
		{
			pos1 = pos_array[y][x];
			my_mlx_pixel_put(img, pos1->x, pos1->y, WHITE + pos1->z * BLUE);
			if (pos_array[y][x + 1] != NULL)
			{
				pos2 = pos_array[y][x + 1];
				print_line(pos1, pos2, img, WHITE + pos1->z * BLUE);
			}
			if (pos_array[y + 1] != NULL
				&& pos_array[y + 1][x] != NULL)
			{
				pos2 = pos_array[y + 1][x];
				print_line(pos1, pos2, img, WHITE + pos1->z * BLUE);
			}
			++x;
		}
		++y;
	}
}
