/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:58:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/04 01:35:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_shap(t_data *img, int height, int width)
{
	int	x;
	int	y;

	x = 5;
	while (x < height / 4)
	{
		y = 5;
		while (y < width / 4)
		{
			my_mlx_pixel_put(img, height / 2 + x, width / 2 - y, GREEN);
			my_mlx_pixel_put(img, height / 2 - x, width / 2 - y, RED);
			my_mlx_pixel_put(img, height / 2 + x, width / 2 + y, YELLOW);
			my_mlx_pixel_put(img, height / 2 - x, width / 2 + y, BLUE);
			++y;
		}
		++x;
	}
}

void	print_line_pos(int x1, int y1, int x2, int y2, t_data* data, int color)
{
	const int	dx = x2 - x1;
	const int	dy = y2 - y1;
	const int	e1 = dy * 2;
	const int	e2 = -dx * 2;
	int	x;
	int	y;
	int	e;

	x = x2;
	y = y2;
	e = -dx;
	while (x < x1)
	{
		my_mlx_pixel_put(data, x, y, color);
		if (e += e1 >= 0)
		{
			--y;
			e += e2;
		}
		++x;
	}
}

void	print_line_neg(int x1, int y1, int x2, int y2, t_data* data, int color)
{
	const int	dx = x2 - x1;
	const int	dy = y2 - y1;
	const int	e1 = dy * 2;
	const int	e2 = -dx * 2;
	int	x;
	int	y;
	int	e;

	x = x1;
	y = y1;
	e = -dx;
	while (x < x2)
	{
		my_mlx_pixel_put(data, x, y, color);
		if (e += e1 >= 0)
		{
			++y;
			e += e2;
		}
		++x;
	}
}

void	print_line(int x1, int y1, int x2, int y2, t_data *data, int color)
{
	if (x1 < x2 && y1 < y2)
		print_line_neg(x1, y1, x2, y2, data, color);
	else if (x2 < x1 && y2 < y1)
		print_line_neg(x2, y2, x1, y1, data, color);
	else if (x2 < x1 && y1 > y2)
		print_line_pos(x1, y1, x2, y2, data, color);
	else
		print_line_pos(x2, y2, x1, y1, data, color);
}
