/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 19:14:08 by rbroque          ###   ########.fr       */
/*   Updated: 2022/12/03 03:38:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_win	*window;
	t_list	*lst;
	int		fd;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("assets/test_maps/42.fdf", O_RDONLY);
	lst = get_pos(fd, 20);
	window = init_window(HEIGHT, WIDTH, "Nice");
	print_map(lst, window->data);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
	loop(window);
	destroy_window(window);
	close(fd);
	return (EXIT_SUCCESS);
}
