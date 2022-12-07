/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 23:03:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_pos ***pos_array, t_data *img)
{
	size_t	x;
	size_t	y;
	t_pos	*curr_pos;

	x = 0;
	y = 0;
	while (pos_array[y] != NULL)
	{
		x = 0;
		while (pos_array[y][x] != NULL)
		{
			curr_pos = pos_array[y][x];
			my_mlx_pixel_put(img, curr_pos->x, curr_pos->y, WHITE + curr_pos->z * BLUE);
			++x;
		}
		++y;
	}
}
