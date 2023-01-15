/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 03:16:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh(t_win *window)
{
	mlx_destroy_image(window->mlx_ptr, window->data.img);
	init_data(window->mlx_ptr, &window->data);
	cpy_vertex_map(window->map.vcpy, window->map.vertex, window->map.x_size, window->map.y_size);
	transform_map(&window->map);
	display_map(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
}
