/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:09:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 14:50:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_win *window, char ***parsing)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr != NULL)
	{
		window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, WINDOW_TITLE);
		init_data(window->mlx_ptr, &window->data);
	}
	init_map(&window->map, parsing);
}
