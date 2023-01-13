/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:39:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 16:40:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (EXIT_SUCCESS);
}

// ANGLE

static void	change_angle(t_win *ptr, double rotation)
{
	ptr->map.angle += rotation;
}

int	increase_angle(t_win *window)
{
	change_angle(window, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_angle(t_win *window)
{
	change_angle(window, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

// ZOOM

static void	change_zoom(t_win *window, long zoom_shift)
{
	window->map.zoom += zoom_shift;
}

int	increase_zoom(t_win *window)
{
	if (window->map.zoom < SIZE_MAX - ZOOM_SHIFT)
		change_zoom(window, ZOOM_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_zoom(t_win *window)
{
	if (window->map.zoom > ZOOM_SHIFT)
		change_zoom(window, -ZOOM_SHIFT);
	return (EXIT_SUCCESS);
}
