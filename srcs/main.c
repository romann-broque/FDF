/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/04 22:04:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	img;
	t_win	*window;
	int		height = HEIGHT;
	int		width = WIDTH;

	if (ac > 1)
		height = atoi(av[1]);
	if (ac > 2)
		width = atoi(av[2]);
	window = init_window(height, width, "Nice");
	img.img = mlx_new_image(window->mlx_ptr, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	print_line(0, 10, 1, width - 1, &img, GREEN);

	int	x_center = height / 2;
	int	y_center = width / 2;
	int	curr_y = y_center - 150;

	while (curr_y < y_center + 150)
	{
		print_line(x_center, y_center, x_center + 200, curr_y, &img, GREEN)
		++curr_y;
	}
//	print_line(0, 10, 1, width - 1, &img, GREEN);
//	print_line(0, width, height, 0, &img, GREEN);
	print_ref(&img, height, width);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img.img, 0, 0);
	loop(window);
	destroy_window(window);
	return (0);
}
