/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/12/06 21:14:34 by rbroque          ###   ########.fr       */
=======
/*   Updated: 2022/12/03 03:38:33 by rbroque          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

<<<<<<< Updated upstream
=======
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
		my_mlx_pixel_put(img, x * x, y, 0x00FF0000);
		++x;
		if (y < width)
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

>>>>>>> Stashed changes
int	main(int ac, char **av)
{
	t_win	*window;
	int		height = HEIGHT;
	int		width = WIDTH;

	if (ac > 1)
		height = atoi(av[1]); // change atoi->ft_atoi
	if (ac > 2)
		width = atoi(av[2]); // change atoi->ft_atoi
	window = init_window(height, width, "Nice");
//	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
	loop(window);
	destroy_window(window);
	return (0);
}
