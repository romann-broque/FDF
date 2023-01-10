/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:55:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 13:54:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	display_map(t_win *window)
{
	if (window->map.vertex)
	{
		print_map(&window->data, &window->map);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
	}
}

void	display_window(t_win *window)
{
	transform_map(&window->map);
	display_map(window);
	if (window->map.vertex != NULL)
		loop(window);
}
