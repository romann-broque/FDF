/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:09:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 14:50:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (window != NULL)
	{
		window->mlx_ptr = mlx_init();
		window->win_ptr = mlx_new_window(window->mlx_ptr, HEIGHT, WIDTH, "FDF");
		window->data = init_data(window->mlx_ptr);
	}
	return (window);
}
