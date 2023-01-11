/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 23:48:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_data *data, int x1, int y1, const int x2, const int y2)
{
	int	dx;
	int	dy;
	int	e;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		put_pixel(data, x1, y1, WHITE);
		++x1;
		e -= dy;
		if (e <= 0)
		{
			++y1;
			e += dx;
		}
	}
}

void	display_line_test(t_win *window)
{
	size_t	i;

	i = 0;
	while (i < HEIGHT / 2)
	{
		put_line(&window->data, 0, i, WIDTH / 2, HEIGHT / 2);
		++i;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
}
