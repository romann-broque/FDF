/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_view.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:45:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/26 14:46:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_view(t_win *window)
{
	window->map.view = E_FREE;
	return (EXIT_SUCCESS);
}

int	iso_view(t_win *window)
{
	window->map.view = E_ISOMETRIC;
	window->map.x_angle = -M_PI / 2 + 1 / sqrt(2);
	window->map.y_angle = 0;
	window->map.z_angle = M_PI / 4;
	return (EXIT_SUCCESS);
}

int	milit_view(t_win *window)
{
	window->map.view = E_MILITARY;
	window->map.x_angle = 0;
	window->map.y_angle = 0;
	window->map.z_angle = M_PI / 4;
	return (EXIT_SUCCESS);
}
