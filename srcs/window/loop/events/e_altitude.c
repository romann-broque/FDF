/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_altitude.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 12:26:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_altitude(t_win *window, double altitude_shift)
{
	window->map.altitude += altitude_shift;
}

int	increase_altitude(t_win *window)
{
	if (window->map.altitude < INT_MAX - ALTITUDE_SHIFT)
		change_altitude(window, ALTITUDE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_altitude(t_win *window)
{
	if (window->map.altitude > INT_MIN + ALTITUDE_SHIFT)
		change_altitude(window, -ALTITUDE_SHIFT);
	return (EXIT_SUCCESS);
}

int	increase_altitude_boost(t_win *window)
{
	change_altitude(window, ALTITUDE_SHIFT_BOOST);
	return (EXIT_SUCCESS);
}

int	decrease_altitude_boost(t_win *window)
{
	change_altitude(window, -ALTITUDE_SHIFT_BOOST);
	return (EXIT_SUCCESS);
}
