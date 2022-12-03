/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:58:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/03 21:59:43 by rbroque          ###   ########.fr       */
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

	x = 1;
	while (x < height / 2)
	{
		my_mlx_pixel_put(img, height / 2 + x, width / 2, 0x00FF0000);
		my_mlx_pixel_put(img, height / 2 - x, width / 2, 0x00FF0000);
		++x;
	}
	y = 1;
	while (y < width / 2)
	{
		my_mlx_pixel_put(img, height / 2, width / 2 + y, 0x00FF0000);
		my_mlx_pixel_put(img, height / 2, width / 2 - y, 0x00FF0000);
		++y;
	}
}
