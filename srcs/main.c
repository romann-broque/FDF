/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/03 02:21:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	y = 1;
	while (x < height / x)
	{
		my_mlx_pixel_put(img, , y * y, 0x00FF0000);
		++x;
		++y;
	}
/*
	y = 0;
	while (y < width / 2)
	{
		my_mlx_pixel_put(img, height / 2, width / 2 + y, 0x00FF0000);
		my_mlx_pixel_put(img, height / 2, width / 2 - y, 0x00FF0000);
		++y;
	}
*/
}

int	main(int ac, char **av)
{
	t_data	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		height = 500;
	int		width = 500;

	if (ac > 1)
		height = atoi(av[1]);
	if (ac > 2)
		width = atoi(av[2]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, height, width, "Nice !");
	img.img = mlx_new_image(mlx_ptr, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_shap(&img, height, width);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
