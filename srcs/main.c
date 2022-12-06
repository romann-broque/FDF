/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 02:33:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

t_pos	*init_pos(int x, int y)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (new != NULL)
		set_pos(new, x, y);
	return (new);
}

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
//
	int		x_center = height / 2;
	int		y_center = width / 2;
	t_pos	*center = init_pos(x_center, y_center);
	t_pos	*pos = init_pos(x_center + 100, y_center - 200);
	t_pos	*corner1 = init_pos(0, 0);
	t_pos	*corner2 = init_pos(HEIGHT, 0);
	t_pos	*corner3 = init_pos(0, WIDTH);
	t_pos	*corner4 = init_pos(HEIGHT, WIDTH);

	print_ref(&img, height, width);
	print_line(corner1, corner4, &img, RED);
	print_line(corner2, corner3, &img, RED);
	while (pos->y <= center->y + 200)
	{
		printf("x --> %d; y --> %d\n", pos->x, pos->y);
		print_line(center, pos, &img, BLUE);
		++pos->y;
	}
//
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img.img, 0, 0);
	loop(window);
	destroy_window(window);
	return (0);
}
