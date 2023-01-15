/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:39:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 19:11:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (EXIT_SUCCESS);
}

// ANGLE

static void	change_angle(double *angle, double rotation)
{
	*angle += rotation;
}

int	increase_x_angle(t_win *window)
{
	change_angle(&window->map.x_angle, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_x_angle(t_win *window)
{
	change_angle(&window->map.x_angle, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	increase_y_angle(t_win *window)
{
	change_angle(&window->map.y_angle, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_y_angle(t_win *window)
{
	change_angle(&window->map.y_angle, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	increase_z_angle(t_win *window)
{
	change_angle(&window->map.z_angle, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_z_angle(t_win *window)
{
	change_angle(&window->map.z_angle, -ANGLE_SHIFT);
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

// ALTITUDE

static void	change_altitude(t_win *window, double altitude_shift)
{
	window->map.altitude += altitude_shift;
}

int	increase_altitude(t_win *window)
{
//	if (window->map.altitude < INT_MAX - ALTITUDE_SHIFT)
		change_altitude(window, ALTITUDE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_altitude(t_win *window)
{
//	if (window->map.altitude > INT_MIN + ALTITUDE_SHIFT)
		change_altitude(window, -ALTITUDE_SHIFT);
	return (EXIT_SUCCESS);
}
