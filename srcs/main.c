/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/03 17:12:24 by rbroque          ###   ########.fr       */
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

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

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
#include <stdio.h>

int	close_window(int key, t_win *ptr)
{
	if (key == ESCAPE_KEY)
		mlx_loop_end(ptr->mlx_ptr);
	return (0);
}

t_win	*init_window(const int height, const int width, char *title)
{
	t_win	*new;

	new = (t_win *)malloc(sizeof(t_win));	
	if (new != NULL)
	{
		new->mlx_ptr = mlx_init();
		new->win_ptr = mlx_new_window(new->mlx_ptr, height, width, title);
	}
	return (new);
}

void	destroy_window(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_win	*window;
	int		height = 500;
	int		width = 500;

	if (ac > 1)
		height = atoi(av[1]);
	if (ac > 2)
		width = atoi(av[2]);
	window = init_window(height, width, "Nice");
	img.img = mlx_new_image(window->mlx_ptr, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_shap(&img, height, width);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img.img, 0, 0);
	mlx_key_hook(window->win_ptr, close_window, window);
	mlx_loop(window->mlx_ptr);
	destroy_window(window);
	return (0);
}
