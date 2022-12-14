/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:58:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 18:21:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		my_mlx_pixel_put(data, x, y, color);
}

void	windows_shap(t_data *img, int height, int width)
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

void	print_ref(t_data *img, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	while (x < height)
	{
		my_mlx_pixel_put(img, x, width / 2, DEFAULT_COLOR);
		++x;
	}
	y = 0;
	while (y < width)
	{
		my_mlx_pixel_put(img, height / 2, y, DEFAULT_COLOR);
		++y;
	}
}
