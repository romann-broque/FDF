/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_angle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/26 15:06:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_angle(t_win *window, t_angle angle, double rotation)
{
	window->map.view = E_FREE;
	if (angle == E_XANGLE)
		window->map.x_angle += rotation;
	else if (angle == E_YANGLE)
		window->map.y_angle += rotation;
	else if (angle == E_ZANGLE)
		window->map.z_angle += rotation;
}

int	increase_x_angle(t_win *window)
{
	change_angle(window, E_XANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_x_angle(t_win *window)
{
	change_angle(window, E_XANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	increase_y_angle(t_win *window)
{
	change_angle(window, E_YANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_y_angle(t_win *window)
{
	change_angle(window, E_YANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	increase_z_angle(t_win *window)
{
	change_angle(window, E_ZANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_z_angle(t_win *window)
{
	change_angle(window, E_ZANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}
