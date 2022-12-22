/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:03:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 20:03:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	should_zoom(const int zoom)
{
	return (zoom < MAX_ZOOM_OFFSET);
}

static bool	should_unzoom(const int zoom)
{
	return (zoom > MIN_ZOOM_OFFSET);
}

int	zoom(int key, int x, int y, t_win *window)
{
	t_transform *const	transform = window->transform;

	(void)x;
	(void)y;
	if (key == SCROLL1_KEY && should_zoom(transform->zoom) == true)
		++transform->zoom;
	else if (key == SCROLL2_KEY && should_unzoom(transform->zoom) == true)
		--transform->zoom;
	return (0);
}