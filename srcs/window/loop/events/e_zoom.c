/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_zoom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 17:42:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
