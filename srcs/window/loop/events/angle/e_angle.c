/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_angle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:50:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(t_win *window, t_angle angle, double rotation)
{
	free_view(window);
	if (angle == E_XANGLE)
		window->map.x_angle += rotation;
	else if (angle == E_YANGLE)
		window->map.y_angle += rotation;
	else if (angle == E_ZANGLE)
		window->map.z_angle += rotation;
}
