/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 14:55:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	main(int ac, char **av)
{
	t_win	*window;
	t_pos	***pos_matrix;
	size_t	size;
	int		fd;
	int		ret_val;

	ret_val = EXIT_FAILURE;
	if (ac > 1)
	{
		size = get_matrix_size(av[1]);
		fd = open(av[1], O_RDONLY);
	}
	else
	{
		size = get_matrix_size("assets/test_maps/42.fdf");
		fd = open("assets/test_maps/42.fdf", O_RDONLY);
	}
	if (fd > -1)
	{
		pos_matrix = get_pos_matrix(fd, size);
		window = init_window(HEIGHT, WIDTH, "FDF", pos_matrix, size);
		print_map(window->refr_matrix, window, WHITE);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
		loop(window);
		destroy_window(window);
		close(fd);
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}
