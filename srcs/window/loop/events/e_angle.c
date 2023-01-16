/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_angle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 17:42:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
