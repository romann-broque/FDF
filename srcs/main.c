/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 16:14:14 by rbroque          ###   ########.fr       */
/*   Updated: 2022/12/03 03:38:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_win	*window;
	int		fd;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("assets/test_maps/42.fdf", O_RDONLY);
//	print_map(fd);
	get_map(fd);
	window = init_window(HEIGHT, WIDTH, "Nice");
	loop(window);
	destroy_window(window);
	close(fd);
	return (EXIT_SUCCESS);
}
