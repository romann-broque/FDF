/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_angle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 23:29:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(t_win *window, t_angle angle, double rotation)
{
	if (angle == E_XANGLE)
	{
		free_view(window);
		window->map.x_angle += rotation;
	}
	else if (angle == E_YANGLE)
	{
		free_view(window);
		window->map.y_angle += rotation;
	}
	else if (angle == E_ZANGLE)
		window->map.z_angle += rotation;
}
