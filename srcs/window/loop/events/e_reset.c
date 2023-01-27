/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_reset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:34:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:52:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reset(t_win *window)
{
	center_offset(window);
	window->map.x_angle = 0;
	window->map.y_angle = 0;
	window->map.z_angle = 0;
	window->map.zoom = ZOOM;
	window->map.altitude = ALTITUDE;
	return (EXIT_SUCCESS);
}
